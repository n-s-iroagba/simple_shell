#include "main.h"

/**
* convert -	Converts numbers to a specific base
* @num:		The number to be converted
* @base:	The base the number should be converted into
* Return:	The converted number
*/

char *convert(int num, int base)
{
	static char *Representation = "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*(--ptr) =  Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
