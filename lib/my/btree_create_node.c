/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** create binary tree node
*/

#include "my.h"

btree_t *btree_create_node(char *data)
{
    btree_t *node = malloc(sizeof(btree_t));

    while (!node)
        node = malloc(sizeof(btree_t));
    node->left = 0;
    node->right = 0;
    node->data = my_strdup(data);
    return node;
}
