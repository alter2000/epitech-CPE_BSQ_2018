/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** tests for streams.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"
#include "my.h"

static void redirect(void)
{
    cr_redirect_stdout();
}

Test(print_map, empty, .init = redirect)
{
    char **m = malloc(sizeof(char *) * 4);
    m[0] = my_strdup("asdlfkjahfdlk");
    m[1] = my_strdup("1233219487230");
    m[2] = my_strdup("ayyyyyyy lmao");
    m[3] = 0;

    print_map(m);
    fflush(stdout);
    cr_expect_stdout_eq_str("asdlfkjahfdlk\n"
                        "1233219487230\n"
                        "ayyyyyyy lmao\n");
}
