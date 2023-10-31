#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <limits.h>

void CreateStack(StackType *pStack){
    pStack->top=-1;
}

int Full_Stack(StackType stack){
    return stack.top==MAX-1;
}

int Empty_Stack(StackType stack){
    return stack.top==-1;
}


void push(StackType *pStack,Eltype el){
    if(Full_Stack(*pStack)){
        printf("StackOverFlow!\n");
        return;
    }
    (*pStack).storage[++(*pStack).top]=el;
}

Eltype pop (StackType *pStack){
    if(Empty_Stack(*pStack)){
        printf("StackUnderFlow\n");
    }
    return (*pStack).storage[(*pStack).top--];
}