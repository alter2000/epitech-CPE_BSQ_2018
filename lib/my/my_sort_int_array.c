/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** sort array
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                array[j] ^= array[j + 1];
                array[j + 1] ^= array[j];
                array[j] ^= array[j + 1];
            }
        }
    }
}
