#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to format
 * @format: string parameter
 *
 * Return: number of characters printed, -1 otherwise
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	const char *fmt;
	char *str;
	char c;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	fmt = format;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			_putchar(*fmt);
			count++;
		}
		else
		{
			fmt++;
			if (*fmt == 'c')
			{
				c = (char)va_arg(ap, int);
				_putchar(c);
				count++;
			}
			else if (*fmt == 's')
			{
				str = va_arg(ap, char *);
				count += print_str(str);
			}
			else if (*fmt == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				int num = va_arg(ap, int);
				count += print_number(num);
			}
			else
			{
				_putchar('%');
				_putchar(*fmt);
				count += 2;
			}
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}
