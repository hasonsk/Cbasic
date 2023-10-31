#ifndef  __LLIST_H__
#define  __LLIST_H__

#include <stdio.h>
#include "data_t.h"
#include <stdlib.h>

typedef struct Node
{
    data_t data;
    struct Node *next;
}node;

//=======Create==========
node *createNode(data_t data);

//=======Insert==========
node *insertFirst(node *head,data_t data);
node *insertLast(node *head,data_t data);
node *insertBefore(node *head,node *cur,data_t data);
node *insertAfter(node *head,node *cur,data_t data);

//========Delete==========
node *deleteFirst(node *head);
node *deleteLast(node *head);
node *deleteBeforeNode(node *head,node *cur);
node *deleteAfterNode(node *head,node *cur);
node *deleteAllNode(node *head);

//==========Show==========
void showListNode(node *head);
//==========Retturn Data==
data_t returnDataNode(node *cur);


//=========Search=========

//node *searchNode(node *head) chưa hoàn thiện

#endif