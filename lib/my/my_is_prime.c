/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** find if number is prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    int prime = 1;
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i <= (nb / 2); i++) {
        if (nb % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}
