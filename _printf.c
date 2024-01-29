#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count;

    if (!format)
        return -1;

    va_start(args, format);

    count = 0;
    while (*format)
    {
        if (*format != '%')
        {
            count += write(1, format, 1);
        }
        else
        {
            format++; /* Move past '%' */

            if (*format == '\0')
            {
                count = -1; /* Incomplete format string */
                break;
            }

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s)
                {
                    int len = 0;
                    while (s[len])
                        len++;
                    count += write(1, s, len);
                }
                else
                {
                    count += write(1, "(null)", 6);
                }
            }
            else if (*format == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                /* Invalid specifier, treat as literal '%' */
                count += write(1, "%", 1);
                count += write(1, format, 1);
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

