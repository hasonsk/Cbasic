#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};
typedef struct BST* node;


node create(int value){
    node newnode=(node )malloc(sizeof(node));
    if(newnode == NULL){
        printf("Can't add for NULL");
        return newnode;
    }
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}


node Insert(node root,int value){
    if(root == NULL){
        return create(value);
    }

    if(value > root->data) {
        root->right = Insert(root->right,value);
    }
    else if (value < root->data){
        root->left = Insert(root->left, value);
    }

    return root;
}

void Inoder(node root){
    if(root == NULL)
        return;
    Inoder(root->left);
    printf("%d \n",root->data);
    Inoder(root->right);
}

int main(){
    node root = NULL;
    root = Insert(root,50);
    root = Insert(root,30);
    root = Insert(root,40);
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,60);
    root = Insert(root,70);
    root = Insert(root,45);

    Inoder(root);
    return 0;
}