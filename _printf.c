#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return -1;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
            {
                count += _putchar('%');
            }
            else
            {
                int (*pfunc)(va_list, flags_t *) = get_print(*format);
                if (pfunc)
                    count += pfunc(args, NULL); // Assuming flags are not used in this implementation
                else
                    count += _putchar('%') + _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }
    va_end(args);

    return count;
}

