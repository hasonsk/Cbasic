#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "data_t.h"
#define MAX 50

typedef struct 
{
    int storage[MAX];
    int top;
}Stack_t;

void createStack(Stack_t *pStack);
int isFullStack(Stack_t Stack);
int isEmptyStack(Stack_t Stack);
void push(Stack_t *pStack,int data);
int pop(Stack_t *pStack);

#endif