#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <limits.h>

void createStack(Stack_t *pStack){
    pStack->top=-1;
}

int isFullStack(Stack_t stack){
    return stack.top==MAX-1;
}

int isEmptyStack(Stack_t stack){
    return stack.top==-1;
}


void push(Stack_t *pStack,int el){
    if(isFull(*pStack)){
        printf("StackOverFlow!\n");
        return;
    }
    (*pStack).storage[++(*pStack).top]=el;
}

int pop(Stack_t *pStack){
    if(isEmpty(*pStack)){
        printf("StackUnderFlow\n");
        return INT_MIN;
    }
    return (*pStack).storage[(*pStack).top--];
}