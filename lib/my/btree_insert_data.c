/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** insert data in BST
*/

#include "my.h"

void btree_insert_data(btree_t *root, char *data, int (*cmpf)())
{
    if (!root || !data || !cmpf)
        return;
    btree_t *newnode = btree_create_node(data);

    if (cmpf(data, root->left->data) > 0) {
        newnode->left = root->left;
        root->left = newnode;
    } else {
        newnode->right = root->right;
        root->right = newnode;
    }
}
