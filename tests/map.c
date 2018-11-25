/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** map.c unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "my.h"
#include "bsq.h"

uint_t count_cols(char *);
uint_t count_lines(char *);

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(count_cols, empty)
{
    char *s2 = strdup("12345\n\n");
    char *s3 = strdup("1234\n12\n12341234");

    cr_expect(count_cols(s2) == 5);
    cr_expect(count_cols(s3) == 4);
}

Test(count_cols, zero, .init = redirect, .exit_code = 84)
{
    cr_expect(count_cols(strdup("\n\n\n\n\n\n\n\n\n\n")) == 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("invalid map\n");
}

Test(count_lines, empty)
{
    cr_expect(count_lines(strdup("12345\n\n")) == 2);
    cr_expect(count_lines(strdup("1234\n12\n1234\n\n1234")) == 4);
    cr_expect(count_lines(strdup("\n\n\n\n\n\n\n\n\n\n")) == 10);
    cr_expect(count_lines(strdup("asdfalskdfjhasldkfjhasldkfjasd")) == 0);
}
