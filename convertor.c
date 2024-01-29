#include "main.h"

/**
 * convert - Converts a number and base into a string
 * @num: Input number
 * @base: Input base
 * @lowercase: Flag if hexa values need to be lowercase
 * Return: Result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char buffer[50];
    char *rep;
    char *ptr;

    rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    /* Convert number to string */
    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

