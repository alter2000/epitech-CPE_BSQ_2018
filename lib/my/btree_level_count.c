/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** count tree levels
*/

#include "my.h"

size_t btree_level_count(btree_t const *root)
{
    if (!root)
        return 0;

    return 1 + min(btree_level_count(root->left), \
                    btree_level_count(root->right));
}
