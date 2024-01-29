#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int (*print_function)(va_list, flags_t *);
    const char *format_iterator;
    va_list args;
    flags_t flags = {0, 0, 0};
    int character_count = 0;

    va_start(args, format);

    /* Check if format is NULL or empty */
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);

    /* Check for invalid format specifier */
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    /* Iterate through the format string */
    for (format_iterator = format; *format_iterator; format_iterator++)
    {
        if (*format_iterator == '%')
        {
            format_iterator++;

            /* Handle double percent sign */
            if (*format_iterator == '%')
            {
                character_count += _putchar('%');
                continue;
            }

            /* Handle flags */
            while (get_flag(*format_iterator, &flags))
                format_iterator++;

            /* Get corresponding print function */
            print_function = get_print(*format_iterator);

            /* Call print function or handle unsupported specifier */
            character_count += (print_function)
                                   ? print_function(args, &flags)
                                   : _printf("%%%c", *format_iterator);
        }
        else
        {
            /* Print non-format characters */
            character_count += _putchar(*format_iterator);
        }
    }

    /* Flush remaining characters and clean up */
    _putchar(-1

