/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** execute given function (smth idk)
*/

#include "my.h"

void btree_apply_infix(btree_t *root, long long int (*applyf)(char *))
{
    if (!root || !applyf)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->data);
    btree_apply_infix(root->right, applyf);
}
