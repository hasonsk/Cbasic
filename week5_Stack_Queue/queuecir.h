/*#include <stdio.h>
#include <limits.h>
#define MAX_LENGTH 50

typedef struct{
    int front,rear;
    int array[MAX_LENGTH];
}QueueType;

void CreateQueue(QueueType *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}

int Empty_Queue(QueueType Q){
    return Q.front==-1;
}

int Full_Queue(QueueType Q){
    return (Q.front == 0 && Q.rear == MAX_LENGTH-1) || (Q.rear == (Q.front-1)%(MAX_LENGTH-1));
}

void enQueue(QueueType *pQ,int el){
    if(Full_Queue(*pQ)){
        printf("Queue is FULL\n");
        return;
    }
    if(pQ->front==-1){
        pQ->front=pQ->rear=0;
        pQ->array[pQ->rear]=el;
    }
    else if(pQ->rear==MAX_LENGTH-1&&pQ->front!=0){
        pQ->rear==0;
        pQ->array[pQ->rear]=el;
    }
    else{
        pQ->rear++;
        pQ->array[pQ->rear]=el;
    }
}

int deQueue(QueueType *pQ){
    if(Empty_Queue(*pQ)){
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    int data=pQ->array[pQ->front];
    pQ->array[pQ->front]=-1;
    if(pQ->front==pQ->rear){
        pQ->front=-1;
        pQ->rear=-1;
    }
    else if(pQ->front==MAX_LENGTH-1)
        pQ->front=0;
    else 
        pQ->front++;
    return data;
}
*/

#ifndef __QUEUECIR_H__
#define __QUEUECIR_H__
#define MAX_LENGTH 50
#include <stdio.h>
typedef struct{
    int front,rear;//front : phan tu chua gia tri dau tien, rear: phan tu chua gia tri cuoi cung
    int array[MAX_LENGTH];
}QueueType;

void CreateQueue(QueueType *pQ);
int Empty_Queue(QueueType Q);
int Full_Queue(QueueType Q);
void enQueue(QueueType *pQ,int el);
int deQueue(QueueType *pQ);

#endif