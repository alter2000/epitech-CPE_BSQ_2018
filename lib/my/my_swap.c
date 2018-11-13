/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** swap 2 numbers given by pointers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}
