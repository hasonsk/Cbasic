#include "queue.h"
#include <stdio.h>
#include <limits.h>

void CreateQueue(QueueType *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}

int Empty_Queue(QueueType Q){
    return Q.front==-1;
}

int Full_Queue(QueueType Q){
    return Q.rear-Q.front+1==MAX_LENGTH;
}

void EnQueue(QueueType *pQ,int X){
    if(!Full_Queue(*pQ)){
        if(Empty_Queue(*pQ))
            pQ->front=0;
        pQ->rear =pQ->rear+1;
        pQ->array[pQ->rear]=X;
    }
    else printf("Queue is full");
}

int DeQueue(QueueType *pQ){ 
	if (!Empty_Queue(*pQ)){
          int retVal = pQ->array[pQ->front];
          pQ->front = pQ->front + 1;
          if (pQ->front > pQ->rear) 
            CreateQueue(pQ);
          return retVal;
   } 
   else {
      printf("Queue is empty!");
      return INT_MIN;
   }
} 