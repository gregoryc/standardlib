/*
This script is BSD 2 licensed, the rest of the other code is not - it's public domain.


BSD 2-Clause License

Copyright (c) 2023, Gregory Cohen
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <dirent.h>
#include <libgen.h>
#include <limits.h>
#include <stdio.h>
#include <
#ifdef _WIN32
#define _CRT_RAND_S
#endif
#include <stdlib.h>
>

#include <string.h>

#include <errno.h>
#include <sys/stat.h>

#define print(s) fputs((s), stdout)
#ifdef __cplusplus
#define restrict __restrict__
#endif

#if __GNUC__
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

    static int rename_mode = 0;
static const char *prog_name = NULL;
static int verbose_mode = 0;
static size_t len1 = 0, len2 = 0;

static void err()
{
    perror("Error");
    exit(1);
}

static int is_valid_utf8(const char *str, size_t len)
{
    size_t i = 0;

    while (i < len)
    {
        if ((str[i] & 0x80) == 0)
        {
            // ASCII character (0xxxxxxx)
            i++;
        }
        else if ((str[i] & 0xE0) == 0xC0)
        {
            // 2-byte UTF-8 character (110xxxxx)
            if (i + 1 >= len || (str[i + 1] & 0xC0) != 0x80)
                return 0;
            i += 2;
        }
        else if ((str[i] & 0xF0) == 0xE0)
        {
            // 3-byte UTF-8 character (1110xxxx)
            if (i + 2 >= len || (str[i + 1] & 0xC0) != 0x80 || (str[i + 2] & 0xC0) != 0x80)
                return 0;
            i += 3;
        }
        else if ((str[i] & 0xF8) == 0xF0)
        {
            // 4-byte UTF-8 character (11110xxx)
            if (i + 3 >= len || (str[i + 1] & 0xC0) != 0x80 || (str[i + 2] & 0xC0) != 0x80 || (str[i + 3] & 0xC0) != 0x80)
                return 0;
            i += 4;
        }
        else
        {
            // Invalid UTF-8 encoding
            return 0;
        }
    }

    return 1;
}

int string_replace_with_lens(const char *source, const char *find, const char *replace, size_t source_len, size_t find_len, size_t replace_len, int *caller_should_use_orig_string_without_modification, size_t *num_matches, char **new_text)
{
    size_t matches = 0;

    // Count the occurrences of 'find' in 'source'
    const char *p = source;
    while ((p = strstr(p, find)) != NULL)
    {
        ++matches;
        p += find_len;
    }

    if (matches == 0)
    {
        *caller_should_use_orig_string_without_modification = 1;
        return 0;
    }
    *caller_should_use_orig_string_without_modification = 0;
    *num_matches = matches;

    // Calculate the final length of the replaced string
    size_t final_len = source_len + matches * (replace_len - find_len);

    // Allocate memory for the replaced string
    char *result = (char *)malloc(final_len + 1);
    if (result == NULL)
    {
        return -1;
    }

    *new_text = result;

    // Perform the replacement
    char *rp = result;
    p = source;
    while ((p = strstr(p, find)) != NULL)
    {
        size_t prefix_len = p - source;
        FOUNDATIONAL_LIB_MEMCPY(rp, source, prefix_len);
        rp += prefix_len;
        FOUNDATIONAL_LIB_MEMCPY(rp, replace, replace_len);
        rp += replace_len;
        p += find_len;
        source = p;
    }

    // Copy the remaining part of the source string
    size_t remaining_len = FOUNDATIONAL_LIB_STRLEN(source);
    FOUNDATIONAL_LIB_MEMCPY(rp, source, remaining_len);
    rp[remaining_len] = '\0';

    return 0;
}

static void proc_stdin(const char *restrict one, const char *restrict two)
{
    const size_t inc = 4096;
    size_t size = inc + 1;

    char *data = (char *)malloc(size);

    size_t base = 0;

    size_t num_to_read = inc;

    for (;;)
    {
        if (base + num_to_read > size)
        {
            data = (char *)realloc(data,
                                   (base + num_to_read) + (base + num_to_read) / 2); // 1.5 is safe because lowest it coud be is 0 +
                                                                                     // 4096 * 1.5, which is always bigger than 4096
        }
        size_t br = fread(data + base, 1, num_to_read, stdin);

        base += br;
        if (br < num_to_read)
        {
            data[base] = '\0';
            break;
        }
    }

    int use_orig;
    size_t num_matches;
    char *new_text;

    if (string_replace_with_lens(data, one, two, base, len1, len2, &use_orig, &num_matches, &new_text) == -1)
    {
        err();
    }
    print(new_text);

    free(data);

    if (!use_orig)
    {
        free(new_text);
        return;
    }

    return;
}

static void process_file(const char *restrict filename, const char *restrict one, const char *restrict two)
{

    if (!FOUNDATIONAL_LIB_STRCMP("/dev/stdin", filename))
    {
        if (verbose_mode)
        {
            print("STDIN\n");
        }
        proc_stdin(one, two);
        return;
    }

    if (!strncmp(filename, "-", 1))
    {
        proc_stdin(one, two);
        return;
    }

    FILE *f = fopen(filename, "r");

    if (unlikely(f == NULL))
    {
        printf("Failed to open file: '%s'\n", filename);
        return;
    }

    // Get the size of the file
    fseeko(f, 0, SEEK_END);
    size_t fsize = ftello(f);
    if (fsize == 0)
    {
        fclose(f);
        return;
    }
    fseeko(f, 0, SEEK_SET);

    // Allocate memory for the file content

    char *text = (char *)malloc(fsize + 1);
    if (unlikely(text == NULL))
    {
        fclose(f);
        printf("Memory allocation failed\n");
        return;
    }

    size_t bytes_read = 0;
    size_t total_bytes_read = 0;

    // Read the file content in chunks
    while (total_bytes_read < fsize)
    {
        size_t len_to_read = fsize - total_bytes_read;
        if (len_to_read > 4096)
        {
            len_to_read = 4096;
        }
        bytes_read = fread(text + total_bytes_read, 1, len_to_read, f);
        if (unlikely(bytes_read == 0))
        {
            fclose(f);
            free(text);
            printf("Failed to read file: '%s'\n", filename);
            return;
        }

        if (!is_valid_utf8(text + total_bytes_read, bytes_read))
        {
            // printf("Skipping non-text file '%s'\n", filename);
            fclose(f);
            free(text);
            return;
        }
        total_bytes_read += bytes_read;
    }

    fclose(f);

    text[fsize] = '\0';

    int use_orig;
    size_t num_matches;
    char *new_text;

    if (string_replace_with_lens(text, one, two, total_bytes_read, len1, len2, &use_orig, &num_matches, &new_text) == -1)
    {
        err();
    }

    if (use_orig)
    {
        return;
    }

    const size_t rep_len = FOUNDATIONAL_LIB_STRLEN(new_text);

    f = fopen(filename, "w");
    if (unlikely(f == NULL))
    {
        printf("Failed to open file for writing: '%s'\n", filename);
        return;
    }

    // Write the replaced content to the file
    {
        size_t bytes_written = fwrite(new_text, 1, rep_len, f);
        if (bytes_written == 0)
        {
            fclose(f);
            free(new_text);
            printf("Failed to write file: '%s'\n", filename);
            return;
        }
    }
    free(new_text);
    fclose(f);

    if (num_matches == 1)
    {
        printf("%s: %s: 1 replacement for %s => %s\n", prog_name, filename, one, two);
    }
    else
    {
        printf("%s: %s: %ld replacements for %s => %s\n", prog_name, filename, num_matches, one, two);
    }
}

static void process_directory(const char *directory_path, const char *one, const char *two, int check_file)
{
    if (strstr(directory_path, "/."))
    {
        // printf("Skipping hidden file '%s'\n", filename);
        return;
    }
    DIR *dir = opendir(directory_path);
    if (dir == NULL)
    {
        if (check_file)
        {
            process_file(directory_path, one, two);
            return;
        }
        printf("Failed to open directory: '%s'\n", directory_path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if ((!FOUNDATIONAL_LIB_STRCMP(entry->d_name, ".")) || (!FOUNDATIONAL_LIB_STRCMP(entry->d_name, "..")))
            continue;

        char path[PATH_MAX];
        FOUNDATIONAL_LIB_SNPRINTF(path, sizeof(path), "%s/%s", directory_path, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1)
        {
            printf("Failed to get file information: %s\n", path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode))
        {
            process_directory(path, one, two, 0);
        }
        else if (S_ISREG(statbuf.st_mode))
        {
            if (unlikely(rename_mode))
            {
                int use_orig;
                size_t num_matches;
                char *new_text;

                if (string_replace_with_lens(path, one, two, FOUNDATIONAL_LIB_STRLEN(path), len1, len2, &use_orig, &num_matches, &new_text) == -1)
                {
                    err();
                }

                if (use_orig)
                {
                    continue;
                }

                printf("%s: Renamed %s => %s\n", prog_name, path, new_text);

                if (rename(path, new_text) == -1)
                {
                    FOUNDATIONAL_LIB_FPRINTF(stderr, "%s: Cannot Rename %s => %s: %s\n", prog_name, path, new_text, strerror(errno));
                }
                free(new_text);
            }
            else
            {
                process_file(path, one, two);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv)
{
    prog_name = basename(argv[0]);
    if (argc < 2)
    {
        printf("Usage: %s <find> <replace> [optional list of files instead of "
               "recursive search]\n\nIf a file is \"-\" or stdin, read from stdin "
               "and output to stdout.\nOptions"
               "\n\n\n    -n, -r rename files instead "
               "of replacing contents of files. find and replace in file and dir "
               "names instead"
               "\n\n\n    -v, verbose mode\n\n\n    -- Indicate end of options.\n\n",
               prog_name);
        return 1;
    }

    char *actual_argv[argc];
    int actual_argc = 0;
    int auto_continue = 0;

    size_t lens[argc];

    for (int i = 0; i < argc; ++i)
    {
        if (auto_continue)
            continue;
        {
            size_t len;
            len = FOUNDATIONAL_LIB_STRLEN(argv[i]);

            if (len == 2)
            {
                if (argv[i][0] == '-')
                {
                    switch (argv[i][1])
                    {
                        case '-':
                            auto_continue = 1;
                            continue;
                        case 'n':
                        case 'r':
                            rename_mode = 1;
                            if (verbose_mode)
                            {
                                print("File name replace mode\n");
                            }
                            continue;
                        case 'v':
                            verbose_mode = 1;
                            print("Verbose mode\n");
                            continue;
                    }
                }
            }

            lens[actual_argc] = len;

            actual_argv[actual_argc] = argv[i];
            actual_argc++;
        }
    }
    len1 = lens[1];
    len2 = lens[2];

    if (actual_argc == 3)
    {
        process_directory(".", actual_argv[1], actual_argv[2], 0);
    }
    else if (actual_argc > 3)
    {
        for (int i = 3; i < actual_argc; ++i)
        {
            if (verbose_mode)
            {
                printf("Processing directory '%s'\n", argv[i]);
            }
            process_directory(actual_argv[i], actual_argv[1], actual_argv[2], 1);
        }
    }
    return 0;
}
