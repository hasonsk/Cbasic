//Ha Hong Son - 20215130
//Đảo chuỗi với Stack
#include "stack.h"
#include <stdio.h>

int main(){
    StackType stack ;
    CreateStack(&stack);   //khoi tao stack voi kich thuoc toi da 50 phan tu
    char ch;
    printf("Input String: ");
    while((ch=getchar())!='\n'){
        push(&stack,ch);
    }
    while(!Empty_Stack(stack)){
        ch=pop(&stack);
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}
