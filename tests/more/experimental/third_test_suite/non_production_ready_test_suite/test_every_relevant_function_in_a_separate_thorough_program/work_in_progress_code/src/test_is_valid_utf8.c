#include "../foundationallib.h"
#include <assert.h>
#include <stddef.h>
// Tests for valid UTF-8 sequences
void test_valid_utf8_sequences()
{
    const char *valid_sequences[] = {
        "Hello, world!",    "UTF-8 is awesome 😊", "こんにちは",
        "\xF0\x9F\x98\x8A", // Unicode "grinning face with smiling eyes" emoji
        "\xE2\x82\xAC",     // Euro sign
        "\xE2\x82\xA1"      // Unassigned code point
    };

    for (size_t i = 0; i < sizeof(valid_sequences) / sizeof(valid_sequences[0]); i++)
    {
        assert(is_valid_utf8(valid_sequences[i], len) == 1);
    }
}

// Tests for invalid UTF-8 sequences
void test_invalid_utf8_sequences()
{
    const char *invalid_sequences[] = {
        "Hello, \xF0\x9F\x98 world!",               // Invalid continuation byte
        "UTF-8 is awesome \xF0",                    // Incomplete encoding
        "こんにちは\x80",                           // Overlong encoding
        "Broken \xED\xA0\x80\xED\xB0\x80 sequence", // Surrogate pair
        "This is not \xC0\xAFbinary",
        "This is \xC0z",            // Overlong encoding
        "This is \xE0\x80\x80",     // Overlong encoding
        "This is \xF4\x90\x80\x80", // Code point > U+10FFFF
        "This is \xF8A00000"        // Code point > U+10FFFF
    };

    for (size_t i = 0; i < sizeof(invalid_sequences) / sizeof(invalid_sequences[0]); i++)
    {
        assert(is_valid_utf8(invalid_sequences[i], len) == 0);
    }
}

int main()
{
    test_valid_utf8_sequences();
    test_invalid_utf8_sequences();
    return 0;
}
