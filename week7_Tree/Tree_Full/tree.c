/*
    load <filename>
    AddChildren : them mot con
    Print
    height
    Count
    Store

*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* tree_t;


tree_t create(int data){
    tree_t p = (tree_t)malloc (sizeof(tree_t));

    if(p == NULL){
        printf("Run out of memory!\n");
        return NULL;
    }
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Insert(tree_t *root,int data){
    if(*root == NULL){
        *root = create(data);
        return;
    }

    if((*root)->data > data)
        Insert(&(*root)->right,data);
    else if((*root)->data < data) 
        Insert(&(*root)->left,data);
}


tree_t minValue(tree_t root){
    while (root && root->left != NULL)
         root = root->left;
    return root; 
}
//delete Node
void deleteNode(int x,tree_t* pRoot){
    if((*pRoot) == NULL){
        return;
    }
    if(x < (*pRoot)->data)
       deleteNode(x,&(*pRoot)->left);
    else if(x > (*pRoot)->data)
       deleteNode(x,&(*pRoot)->right);
    else{
        if((*pRoot)->left == NULL)
            (*pRoot) = (*pRoot)->right;
        else if((*pRoot)->right == NULL)
             (*pRoot) = (*pRoot)->left;
        else{
            tree_t tmp = minValue(*pRoot);
            (*pRoot)->data = tmp->data;
            deleteNode(tmp->data,&(*pRoot)->right);
        }
    }
} 


//Free tree
void freeTree(tree_t tree){
    if(tree!=NULL){
        freeTree(tree->left);
        freeTree(tree->right);
        free((void *)tree);
    }
}          

//preorder

void preorder(tree_t root){
    if(root == NULL) 
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//inorder
void inorder(tree_t root){
    if(root == NULL) 
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
//postorder

void postorder(tree_t root){
    if(root == NULL)
         return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void  removekeys(int n, int m, tree_t root){
    if(root == NULL) return;
    if(root->data < n) deleteNode(root->data, &root);
    if(root->data > m) deleteNode(root->data, &root);
    else{
        removekeys(n,m,root->left);
        removekeys(n,m,root->right);
        printf("%d ",root->data);
    }

}

int main(){
    tree_t root = NULL;
    root = create(3);
    Insert(&root,4);
    Insert(&root,2);
    Insert(&root,6);
    Insert(&root,1);
    inorder(root);
    //printf("PREORDER:\n"); preorder(root);
    //printf("\nINORDER:\n");   inorder(root);
    //printf("\nPOSTORDER:\n");   postorder(root);


    int n,m;
    printf("Nhap n: "); scanf("%d ",&n);
    printf("Nhap m: "); scanf("%d ",&m);
    removekeys(n,m,root);
    inorder(root);
    freeTree(root);
}