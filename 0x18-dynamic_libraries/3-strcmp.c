#include "main.h"
/**
 *_strcmp - compares two strings
 *@s1: A pointer to a character that will be changed
 *@s2: A pointer to a character that will also be changed/modified/updated
 *Return: dest
 */
int _strcmp(char *s1, char *s2)
{
    char *p1 = s1;
    char *p2 = s2;
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
    {
        p1++;
        p2++;
    }
    return (*p1 - *p2);
}