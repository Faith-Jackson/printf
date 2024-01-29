#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 * Description: This function uses a local buffer of 1024 to minimize calls to write
 */
int _putchar(char c)
{
    static char buffer[1024];
    static int buffer_index = 0;

    /* Check if buffer is full or character is a flush signal */
    if (c == -1 || buffer_index >= 1024)
    {
        /* Flush buffer to stdout */
        write(1, buffer, buffer_index);
        buffer_index = 0;
    }

    /* Add character to buffer if not a flush signal */
    if (c != -1)
    {
        buffer[buffer_index++] = c;
    }

    return (1); /* Success */
}

/**
 * _puts - Prints a string to stdout
 * @str: Pointer to the string to print
 * Return: Number of characters written
 */
int _puts(char *str)
{
    int char_count = 0;

    /* Iterate through string and print each character */
    while (*str)
    {
        _putchar(*str++);
        char_count++;
    }

    return char_count;
}

