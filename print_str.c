#include "main.h"

/**
 * print_str - prints a string
 * @s: parameter
 *
 * Return: count
 */
int print_str(char *s)
{
	int count = 0;
	char *null_str;

	if (s == NULL)
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
		while (*s != '\0')
		{
			_putchar(*s);
			count++;
			s++;
		}
	}
	return (count);
}
