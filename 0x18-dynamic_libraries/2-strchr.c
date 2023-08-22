#include "main.h"
/**
 * _strchr - Locates a character in a string
 * @s: String
 * @c: Character to search
 * Return: Pointer to the first occurrence of the character c in the string s
 **/

char *_strchr(char *s, char c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return (s + i);
        }
        i++;
    }
    if (s[i] == c)
    {
        return (s + i);
    }
    return (0);
}