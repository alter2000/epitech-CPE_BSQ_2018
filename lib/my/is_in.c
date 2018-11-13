/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** like Python `in' operator
*/

int is_in(char const elem, char const *set)
{
    for (unsigned int i = 0; set[i]; i++)
        if (set[i] == elem)
            return 1;
    return 0;
}
