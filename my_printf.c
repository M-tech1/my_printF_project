#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_putchr_function(char);
int print_base_function(size_t, int);
int print_decimal_function(va_list, char);
int print_string_function(va_list);
int print_number_function(va_list, int);
int print_char_function(va_list);
int print_format_function(va_list, char);
int my_printf(char* restrict, ...);

int print_base_function(size_t unslong, int base_no)
{
    char* ch_array = (char*)malloc(sizeof(char));
  //  if(ch_array != NULL);    /* NULL Check */
    int Index = 0, Counter = 0;
    do
    {
        int modulus = unslong % base_no;
        if (modulus >= 0 && modulus < 10)
            ch_array[Index] = modulus + '0';
        else
            ch_array[Index] = 'a' + modulus - 10;
        ch_array = realloc(ch_array, sizeof(char) + (sizeof(char) * ++Index));
        unslong /= base_no;
    } while (unslong > 0);

    do
    {
        Index--;
        Counter += my_putchr_function(ch_array[Index]);
    } while (Index);
    free(ch_array);
    return Counter;
}

// function that doest the string formatting
// with the placeholers parameters

int print_format_function(va_list ap, char Format)
{
    switch (Format)
    {
        case 'd':
        case 'u':
            return print_decimal_function(ap, Format);
        case 'o':
            return print_number_function(ap, 8);
        case 'p':
        case 'x':
            return print_number_function(ap, 16);
        case 'c':
            return print_char_function(ap);
        case 's':
            return print_string_function(ap);
    }
    return 0;
}

int my_putchr_function(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}

int print_decimal_function(va_list ap, char Formats)
{
    int Current = va_arg(ap, int);
    int Counter = 0;
    if (Current < 0)
    {
        Current = -Current;
        if (Formats == 'd') Counter += my_putchr_function('-');
    }
    Counter += print_base_function(Current, 10);
    return Counter;
}

int print_string_function(va_list ap)
{
    char* String = va_arg(ap, char*);
    int Counter = 0;
    while (*String != '\0')
    {
        char c = *String;
        Counter += my_putchr_function(c);
        String++;
    }

    if (String == (char*)NULL)
    {
        String = "(null)";
    }
    return Counter;
}

int print_number_function(va_list ap, int Base_no)
{
    size_t Current = va_arg(ap, size_t);
    return print_base_function(Current, Base_no);
}

int print_char_function(va_list ap)
{
    char Current = va_arg(ap, int);
    return my_putchr_function(Current);
}

// My main printf costum function...
int my_printf(char* format, ...)
{
    int print_total = 0;
    va_list ap;
    va_start(ap, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(++format) != '\0')
            print_total += print_format_function(ap, *format);
        else
            print_total += my_putchr_function(*format);

        if (*format != '\0') format++;
    }

    va_end(ap);
    return print_total;
}

// ************** Testing my PrintF funtion **********************

int main()
{
    // int x = 10;
    // char str[] = "";
    // my_printf("Martins learning real programming %d", x);
}

/// i also have testing with -> gcc  -Wall -Wextra -Werror -o my_printf
/// my_printf.c