#include <stdio.h>

/**
* _strcmp -	This compares two strings
* @s1:		This is the first string
* @s2:		This is the second string
*
* Return:	0 if the two strings are equal
*			+1 if first string is greater than the second string
*			-1 if first string is less than the second string
*/

int _strcmp(char *s1, char *s2)
{
	int count = 0, count2 = 0;

	while (count == 0)
	{
		if ((*(s1 + count2) == '\0') && (*(s2 + count2) == '\0'))
			break;
		count = *(s1 + count2) - *(s2 + count2);
		count2++;
	}

	return (count);
}
