/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** find smallest prime number
*/

#include "my.h"

int is_prime(int nb)
{
    int prime = 1;
    if (nb <= 1)
        return 0;
    for (int i = 2; i <= (nb / 2); i++) {
        if (nb % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

int my_find_prime_sup(int nb)
{
    for (int i = nb; i < INT_MAX; i++)
        if (is_prime(i))
            return i;
    return -1;
}
