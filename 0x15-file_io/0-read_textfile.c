#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    ssize_t fdd;
    ssize_t wi;
    ssize_t x;

    fdd = open(filename, O_RDONLY);
    if (fdd == -1)
        return (0);
    buf = malloc(sizeof(char) * letters);
    x = read(fdd, buf, letters);
    wi = write(STDOUT_FILENO, buf, x);

    free(buf);
    close(fdd);
    return (wi);
}
