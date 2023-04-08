#include <stdio.h>
#include <stdarg.h>

void my_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char* p = format; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'c': {
                char c = (char) va_arg(args, int);
                putchar(c);
                break;
            }
            case 'd': {
                int d = va_arg(args, int);
                printf("%d", d);
                break;
            }
            case 's': {
                char* s = va_arg(args, char*);
                printf("%s", s);
                break;
            }
            default: {
                putchar(*p);
                break;
            }
        }
    }

    va_end(args);
}

int main()
{
    int age = 42;
    char* name = "martins";
    my_printf("Hello, %s! You are %d years old.\n", name, age);
    return 0;
}
