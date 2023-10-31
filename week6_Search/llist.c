#include <stdio.h>
#include <stdlib.h>
#include "data_t.h"
#include "llist.h"


//=======Create==========
node *createNode(data_t data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}

//=======Insert==========
node *insertFirst(node *head,data_t data){ //done
    node *temp=createNode(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    temp->next=head;
    head=temp;
    return head;
}
node *insertLast(node *head,data_t data){  //done
    if(head==NULL){
        printf("CANNOT INSERT AFTER NULL!\n");
        return head;
    }
    node *newnode=createNode(data);
    node *last=head;
    while(last->next!=NULL)
        last=last->next;
    last->next=newnode;
    return head;
}
node *insertBefore(node *head,node *cur,data_t data){ //done
    if(head==NULL){
        head=insertFirst(head,data);
        return head;
    }
    node *newnode=createNode(data);
    node *temp=head;
    while(temp->next!=cur)
        temp=temp->next;
    newnode->next=cur;
    temp->next=newnode;
    return head;
}
node *insertAfter(node *head,node *cur,data_t data){   //done
    if(head==NULL||cur==NULL){
        printf("CAN NOT INSERT AFTER NULL!\n");
        return head;
    }
    node *newnode =createNode(data);
    newnode->next=cur->next;
    cur->next=newnode;
    return head;
}

//========Delete==========

node *deleteFirst(node *head){
    if(head==NULL) return head;
    node *del=head;
    head=head->next;
    free(del);
    return head;
}
node *deleteLast(node *head){
    if(head==NULL) return head;
    node *del=head;
    node *prev;
    while(del->next==NULL){
        prev=del;
        del=del->next;
    }
    prev->next=del->next;
    free(del);
    return head;
}
node *deleteNode(node *head,node *cur){  //done
    if(head==NULL) return head;
    if(cur==head){
        head=deleteFirst(head);
        return head;
    } 
    node *prev=head;
    while (prev->next==cur)
        prev=prev->next;
    prev->next=cur->next;
    free(cur);
    return head;
}
node *deleteAfterNode(node *head,node *cur){
    if(head==NULL) return head;
    if(cur->next==NULL) return head;
    node *del=cur->next;
    cur->next=del->next;
    free(del);
    return head;
}

node *deleteAllNode(node *head){   
    if(head==NULL) return head;
    node *temp=NULL;
    while(head!=NULL){
        temp=head->next;
        free(head);
        head=temp;
    }
    return head;
}

//==========Show==========
void showListNode(node *head){
    if(head==NULL){
        printf("NO LIST, NO NODE!\n");
        return;
    } 
    node *temp=head;
    while(temp!=NULL){
        showData(temp->data);
        temp=temp->next;
    }
    free(temp);
    return;
}


//=========Search=========

//node *searchNode(node *head) chưa hoàn thiện
