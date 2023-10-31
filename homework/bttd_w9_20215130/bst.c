#include <stdio.h>
#include <string.h>
#include "data.h"
#include "bst.h"
#include <stdlib.h>

tree_t createNode(char word[]){
    tree_t newNode = (node_t *)malloc(sizeof(node_t));
    if(newNode==NULL){
        printf("Can't create new node!\n");
        return NULL;
    }
    data_t newData;
    strcpy(newData.word,word);
    newData.fre=1;
    memcpy(&(newNode->data), &(newData), sizeof(data_t)); 
    newNode->data.fre=1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree_t searchNode(char word[], tree_t root){
    if(root == NULL || strcmp(word, root->data.word) == 0)
        return root;
    if(strcmp(word,root->data.word)<0) 
        return searchNode(word, root->left);
    else 
       return searchNode(word, root->right);
}

void insertNode(char word[],tree_t *root){
    if(*root == NULL){
        *root = createNode(word);
        return;
    }         
    if(strcmp(word,(*root)->data.word)<0)                 
        insertNode(word,&((*root)->left));
    else  
        insertNode(word,&((*root)->right));
    return;
}


void travesal(tree_t root){
    if(root!=NULL){
        travesal(root->left);
        showData(root->data);
        travesal(root->right);
    }
}

void freeTree(tree_t *root) {
    if (*root != NULL) {
        freeTree(&(*root)->left);
        freeTree(&(*root)->right);
        free((void *)(*root));
    }
}
