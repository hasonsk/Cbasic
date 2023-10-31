#include <stdio.h>
#include "queuecir.h"
#include <stdlib.h>

void CreateQueue(QueueType *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}

int Empty_Queue(QueueType Q){
    return Q.front==-1;    //1
}
int Full_Queue(QueueType Q){
    return (Q.front == 0 && Q.rear == MAX_LENGTH-1)||Q.rear==(Q.front-1)%MAX_LENGTH;
}
void enQueue(QueueType *pQ,int el){//lam lai
    if(Full_Queue(*pQ))
    {
        printf("Queue is full!\n");
        return;
    }
    else if(pQ->front==-1)//khoi tao :initailize
    {
        pQ->front=pQ->rear=0;
        pQ->array[pQ->rear]=el;
    }
    else if(pQ->rear==MAX_LENGTH-1 && pQ->front!=0)
    {
        pQ->rear=0;
        pQ->array[pQ->rear]=el;
    }
    else {
        pQ->array[++pQ->rear]=el;
    }
}

//Lay mot phan tu ra khoi QUEUE
int deQueue(QueueType *pQ){
    if(Empty_Queue(*pQ)){
        printf("Queue is Empty\n");
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
