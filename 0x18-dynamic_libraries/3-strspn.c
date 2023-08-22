#include "main.h"
/**
 * _strspn - Locates a character in a string
 * @s: This is the main C string to be scanned.
 * @accept: This is the string containing the list of characters to match in s
 * Return: return count
 **/
 unsigned int _strspn(char *s, char *accept)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *p1, *p2;
    p1 = s;
    p2 = accept;
    while (p1[i] != '\0')
    {
        j = 0;
        while (p2[j] != '\0')
        {
            if (p1[i] == p2[j])
            {
                count++;
                break;
            }
            j++;
        }
        if (p2[j] == '\0')
        {
            break;
        }
        i++;
    }
    return (count);
}