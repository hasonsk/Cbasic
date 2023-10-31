#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


Node* creat_node(data_T data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("Error! cannot create!\n");
        return 0;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void show_node(Node *head){
    if(head==NULL){
        printf("No item to show!\n");
        return;
    }
    while(head->next!=NULL){
        printf("%-20s%-20s%-20s\n",head->data);
        head=head->next;
    }
    return;
}

int compare(data_T a, data_T b){
    if(strcmp(a.name,b.name)!=0) return 0;
    if(strcmp(a.tel,b.tel)!=0) return 0;
    if(strcmp(a.mail,b.mail)!=0) return 0;
    return 1;
}

Node *search_node(Node *head, data_T x){
    if(head==NULL) return (NULL);
    if(compare((head->next)->data,x))  
      return (head);
    else
      return (search_node(head->next,x));
}


void insert_head(Node **head,data_T data){
    Node *temp=create_Node(data);
    if(*head == NULL){
        *head = temp;
    }
    temp->next=*head;
    *head=temp;
}

void insert_last(Node **head, data_T data){
    if(*head == NULL){
        Node *temp=create_Node(data);
        *head = temp;
    }
    else 
        insert_last(&(*head)->next,data);
}

Node *predecessor_node(Node *head, data_T x){
    if(head==NULL||head->next==NULL){
        printf("Error: prodecessor sought on null Node.\n");
        return (NULL);
    }
    if((compare((head->next)->data,x)))
        return (head);
    else 
        return (predecessor_node(head->next,x));
}


void delete_node(Node **head, data_T x){
    Node *p;
    Node *pred; //predecessor pointer
    p = search_node(*head,x);
    if(p!=NULL){
        pred=predecessor_node(*head,x);
        if(pred==NULL)
            *head=p->next;
        else
            pred->next=p->next;
        free(p);
    }
}

void delete_all_node(Node **head){
    Node *p;
    for(p=*head;*head!=NULL;*head=p->next){
        free(*head);
        p=p->next;
    }
    show_node(*head);
}