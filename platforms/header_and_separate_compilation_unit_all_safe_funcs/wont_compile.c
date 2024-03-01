#include "foundationallib_noninline.h"

/*
/usr/bin/ld: /tmp/ccoq7JmC.o: in function `main':
wont_compile.c:(.text+0x13): undefined reference to `shellescape'
collect2: error: ld returned 1 exit status
*/
int main() { puts(shellescape("foo")); }
