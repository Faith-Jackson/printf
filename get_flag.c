#include "main.h"

/**
 * get_flag - Turns on flags if _printf finds a flag specifier
 * @s: Character that holds the flag specifier
 * @f: Pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
    int flag_turned_on = 0; // Initialize flag to indicate if a flag has been turned on

    switch (s)
    {
        case '+':
            f->plus = 1; // Turn on '+' flag
            flag_turned_on = 1;
            break;
        case ' ':
            f->space = 1; // Turn on ' ' flag
            flag_turned_on = 1;
            break;
        case '#':
            f->hash = 1; // Turn on '#' flag
            flag_turned_on = 1;
            break;
    }

    return (flag_turned_on); // Return 1 if a flag has been turned on, 0 otherwise
}

