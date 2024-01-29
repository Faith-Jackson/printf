fndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
  * when a flag specifier is passed to _printf()
   * @plus: flag for the '+' character
    * @space: flag for the ' ' character
     * @hash: flag for the '#' character
      */
      typedef struct flags
      {
	          int plus;
		      int space;
		          int hash;
      } flags_t;

      /**
       * struct printHandler - struct to choose the right function depending
        * on the format specifier passed to _printf()
	 * @c: format specifier
	  * @f: pointer to the correct printing function
	   */
	   typedef struct printHandler
	   {
		       char c;
		           int (*f)(va_list ap, flags_t *f);
	   } ph;

	   int _printf(const char *format, ...);
	   int _putchar(char c);

	   /* Integer conversion specifiers */
	   int print_int(va_list args, flags_t *flags);
	   int print_unsigned(va_list args, flags_t *flags);
	   int print_octal(va_list args, flags_t *flags);
	   int print_hex(va_list args, flags_t *flags);
	   int print_hex_big(va_list args, flags_t *flags);
	   int print_binary(va_list args, flags_t *flags);

	   /* String and character conversion specifiers */
	   int print_string(va_list args, flags_t *flags);
	   int print_char(va_list args, flags_t *flags);
	   int print_percent(va_list args, flags_t *flags);

	   /* Custom conversion specifiers */
	   int print_rot13(va_list args, flags_t *flags);
	   int print_rev(va_list args, flags_t *flags);
	   int print_bigS(va_list args, flags_t *flags);
	   int print_address(va_list args, flags_t *flags);

#endif /* MAIN_H */

