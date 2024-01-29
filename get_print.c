#include "main.h"

/**
 * get_print - Selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: Character that holds the conversion specifier
 * Description: The function loops through the func_arr[] array
 * to find a match between the specifier passed to _printf
 * and the first element of the struct, and then returns the
 * appropriate printing function
 * Return: A pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
    /* Array of structs mapping conversion specifiers to printing functions */
    ph func_arr[] = {
        {'i', print_int},
        {'s', print_string},
        {'c', print_char},
        {'d', print_int},
        {'u', print_unsigned},
        {'x', print_hex},
        {'X', print_hex_big},
        {'b', print_binary},
        {'o', print_octal},
        {'R', print_rot13},
        {'r', print_rev},
        {'S', print_bigS},
        {'p', print_address},
        {'%', print_percent}
    };

    /* Number of elements in the func_arr[] array */
    int num_functions = sizeof(func_arr) / sizeof(func_arr[0]);

    register int i;

    /* Loop through func_arr[] to find matching printing function */
    for (i = 0; i < num_functions; i++)
    {
        if (func_arr[i].c == s)
        {
            return (func_arr[i].f); // Return pointer to matching printing function
        }
    }

    return (NULL); // No matching printing function found
}

