#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    if (!format)
        return -1;

    va_start(args, format);

    ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++; /* Move past '%' */

            if (*ptr == '\0')
            {
                /* Handle incomplete format string */
                count += write(1, "%", 1);
                break;
            }

            if (*ptr == 'c')
            {
                /* Handle character specifier */
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (*ptr == 's')
            {
                /* Handle string specifier */
                char *s = va_arg(args, char *);
                int len = 0;
                while (s[len])
                    len++;
                count += write(1, s, len);
            }
            else if (*ptr == '%')
            {
                /* Handle percent specifier */
                count += write(1, "%", 1);
            }
            else
            {
                /* Invalid specifier, treat as literal '%' */
                count += write(1, "%", 1);
                count += write(1, ptr, 1);
            }
        }
        else
        {
            /* Write character to stdout */
            count += write(1, ptr, 1);
        }

        ptr++;
    }

    va_end(args);
    return count;
}

