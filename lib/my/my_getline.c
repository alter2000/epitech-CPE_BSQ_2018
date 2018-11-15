/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** getline and getdelim implementations
*/

#include "my.h"

char *getd(int fd, char **lp, int *n, char delim) {
    int ch = 0;
    unsigned int pos = 0;

    if (!lp || !fd || !n || read((size_t) fd, &ch, 1) != 1 || (char) ch == EOF)
        return 0;
    while (!*lp) {
        *n = 30;
        *lp = malloc(*n);
    }
    while(ch != EOF) {
        ((unsigned char *)(*lp))[pos++] = ch;
        if (ch == delim)
            break;
        read((size_t) fd, &ch, 1);
    }
    (*lp)[pos] = '\0';
    return *lp;
}

char *getl(int fd, char **lp, int *blen) {
    return getd(fd, lp, blen, '\n');
}
