#ifndef __STACK_H__

#define __STACK_H__

#define MAX 50

#include <stdio.h>

typedef int Eltype;

typedef struct {
    Eltype storage[MAX];
    int top;
}StackType;

void CreateStack(StackType *pStack);
int FullStack(StackType pStack);
int Empty_Stack(StackType pStack);
void push(StackType *pStack,Eltype el);
Eltype pop(StackType *pStack);
#endif