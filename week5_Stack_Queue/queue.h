#ifndef __QUEUE_H__

#define __QUEUE_H__
#include <stdio.h>
#define MAX_LENGTH 50

typedef struct 
{
    int front,rear;
    int array[MAX_LENGTH];
}QueueType;

void CreateQueue(QueueType *pQ);
int Empty_Queue(QueueType Q);
int Full_Queue(QueueType Q);
void EnQueue(QueueType *pQ,int el);
int DeQueue(QueueType *pQ);

#endif