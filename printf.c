#include "main.h"
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

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr != '%')
        {
            /* Write character to stdout */
            write(1, ptr, 1);
            count++;
        }
        else
        {
            ptr++; /* Move to the next character after '%' */

            if (*ptr == 'c')
            {
                /* Handle character specifier */
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*ptr == 's')
            {
                /* Handle string specifier */
                char *s = va_arg(args, char *);
                while (*s != '\0')
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                /* Handle percent specifier */
                write(1, "%", 1);
                count++;
            }
        }
    }

    va_end(args);
    return count;
}

