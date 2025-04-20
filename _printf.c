#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
	char *str, *null_str;
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
				if (str == NULL)
				{
					null_str = "(null)";
					while (*null_str != '\0')
					{
						_putchar(*null_str);
						count++;
						null_str++;
					}
				}
				else
				{
					while (*str != '\0')
					{
						_putchar(*str);
						count++;
						str++;
					}
				}
			}
			else if (*fmt == '%')
			{
				_putchar('%');
				count++;
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
