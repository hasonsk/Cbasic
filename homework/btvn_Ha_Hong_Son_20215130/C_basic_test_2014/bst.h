#ifndef __BST_H__
#define __BST_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char username[30];  // !!' '
    char password[30];  // >=6 ' '
    float grade;
}data_t;

typedef struct bst
{
    struct bst *left;
    struct bst *right;
    data_t data;
}bst,*root;



data_t makeData();

void Insert(bst **root);


#endif