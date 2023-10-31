#include <stdio.h>
#include "bst.h"

int check_space(char s[], int n){
    for(int i=0;i<n;i++)
        if(s[i]==' ') return 0;
    return 1;
}



data_t makeData(){
    data_t *newData = (data_t *)malloc(sizeof(data_t));
    while(1){
        printf("Nhap username: ");
        fgets(newData->username, 30,stdin);
        if(check_space(newData->username,strlen(newData->username))==1) break;
        else {
            printf("Loi cu phap! Nhap lai.\n");
            strcpy(newData->username,"\0");
        }
    }
    while (1){
        printf("Nhap password: ");
        fgets(newData->password,30,stdin);
        if(check_space(newData->password,strlen(newData->password))&&strlen(newData->password)>=6) break;
        else{
            printf("Loi cu phap! Nhap lai.\n");
            strcpy(newData->password,"\0");
        }
    }
    printf("Nhap diem: "); scanf("%f",&newData->grade);
    return *newData;
}

void Insert(bst **root){
    bst *newNode = (bst*)malloc(sizeof(bst));
        newNode->data = makeData();
        newNode->left = NULL;
        newNode->right = NULL;
    if(*root == NULL){
        *root = newNode;
        free(newNode);
        return;
    }
    if(strcmp(newNode->data.username,(*root)->data.username)) Insert(&((*root)->right));
    else Insert(&((*root)->left));
}

