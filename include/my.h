/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** muh library
*/

#ifndef _MY_H_
#define _MY_H_

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned long long int ull_t;
typedef unsigned long int ul_t;
typedef unsigned int uint_t;
typedef long long int ll_t;
typedef long int l_t;

unsigned long long int my_strlen(char const *);
int my_putchar(int const);
long long int my_putstr(char const *);
int my_put_nbr(int);
int my_put_nbr_base(int, char const *);
int my_count_digits(int const);
int my_count_digits_rec(int const, int const);
long long int my_getnbr(char const *);
long long int getnbr_rec(char const *, long long int);
long long int my_strtoll(char *, char **, long long int);
char *my_itoa(int);
int is_in(char, char *);

void my_swap(int *, int *);

char *my_strcpy(char *, char const *);
char *my_strcnpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
void my_showstr(char const *);
int my_show_word_array(char const **);
int my_show_int_array(char const **);

char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strncpy(char *, char const *, int);

int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_isdigit(char);
int my_isupper(char);
int my_islower(char);
int my_isalpha(char);
int my_isspace(char);
int my_isprintable(char);

char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
void *my_memset(char *, short, size_t);
void *my_nul(char *, size_t);
char *my_realloc(char *, int);

int my_atoi(char const *);
long long int my_atoll(char const *);
char *getl(int, char **, int *);
char *getd(int, char **, int *, char);

typedef struct btree
{
    struct btree *left;
    struct btree *right;
    char *data;
} btree_t;

btree_t *btree_create_node(char *);
void btree_apply_infix(btree_t *, long long int (*)(char *));
void btree_apply_prefix(btree_t *, long long int (*)(char *));
void btree_insert_data(btree_t *, char *, int (*)());
size_t btree_level_count(btree_t const *);


static inline int min(int i, int j)
{
    return (i < j) ? i : j;
}

static inline int max(int i, int j)
{
    return (i > j) ? i : j;
}

static inline signed char errb(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "err: no error string\n", 21);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    _exit(84);
}

static inline signed char err(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "errb: no error string\n", 22);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    return 0;
}

static inline signed char errc(char *buf, char const *errstr)
{
    if (!errstr || !*errstr || !buf || !*buf) {
        write(2, "errc: no error string or buffer\n", 32);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    free(buf);
    return 0;
}

#endif // _MY_H_
