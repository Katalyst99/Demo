#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string
 * Return: The length of string
 */
int _strlen(const char *s)
{
	int len = 0;


	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating,
 * null byte (\0) to the buffer pointed to by dest.
 * @dest: copy to
 * @src: copy from (source)
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int len = 0;

	while (len >= 0)
	{
		dest[len] = src[len];
		if (src[len] == '\0')
			break;
		len++;
	}
	return (dest);
}

/**
 * _strcat - A function that concatenates two strings.
 * @src: The source
 * @dest: The destination
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}

	for (i = 0; src[i] != '\0'; i++, len++)
	{
		dest[len] = src[i];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings, should work exactly like strcmp
 * @s1: First string
 * @s2: Second string
 * Return: 0 if s1 and s2 are equal, another number if not.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _strdup - A function that is used to create a duplicate of a string
 * @str: The pointer to the string that is to be duplicated
 * Return: A pointer to the new string
 */
char *_strdup(char *str)
{
	size_t i = 0;
	char *newstr = NULL;
	size_t len;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		i++;
	}

	len = i + 1;
	newstr = malloc(len);
	if (newstr == NULL)
	{
		return (NULL);
	}
	
	for (i = 0; i < len; i++)
	{
		newstr[i] = str[i];
	}
	return (newstr);

}
