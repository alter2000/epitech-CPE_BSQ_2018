/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** atoi implementation
*/

long long int my_atoll(char **s)
{
    long long int nbr = 0;

    for (;**s >= '0' && **s <= '9'; (*s)++)
        nbr = nbr * 10 + (**s - '0');
    return nbr;
}
