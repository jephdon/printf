#include "main.h"

/**
 * print_number - prints signed int
 * @n: parameter
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	char buffer[12];
	int i = 0, count = 0;
	unsigned int num;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}
	return (count);
}
