#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct node
{
    data_t data;
    struct node *left;
    struct node *right;
}node_t;

typedef struct node *tree_t;

//tao mot phan tu, duyet, them mot phan tu, xoa mot phan tu, xoa toan bo, 

tree_t createNode(char word[]);
void insertNode(char word[], tree_t *root);
tree_t searchNode(char *word,tree_t root);
void freeTree(tree_t *root);
void travesal(tree_t root);

#endif