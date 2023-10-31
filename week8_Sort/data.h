#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>

struct Address
{
    char name[30];
    char tel[18];
    char mail[35];
};
typedef struct Address data_T;

typedef struct node
{
    data_T data;
    struct node *next;
}Node;

Node *create_node(data_T data);
void show_Node(Node *head);
int compare(data_T a, data_T b);
Node *search_node(Node *head, data_T x);
Node *predecessor_node(Node *head, data_T x);
void insert_head(Node **head,data_T data);
void insert_last(Node **head, data_T data);
void delete_all_node(Node **head);
void delete_node(Node **head, data_T x);

#endif