#include "monty.h"
/**
 * _strcmp - compares two strings.
 * @s1: str1 compared
 * @s2: str2 compared
 * Return: 0 if s1 and s2 are equals.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch - look for a char inside a string
 * @s: string
 * @c: char
 * Return: 1 if success else 0
 */

int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			break;
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - cut a string into tokens
 * @s: string
 * @d: delimiters
 * Return: first partition
 */

char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1, *ultimo = '\0', s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1, *ultimo = '\0', ultimo++, s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
			j++, i++;
	}
	return (NULL);
}
