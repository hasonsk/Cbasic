#include <stdio.h>
#include "queuecir.h"
#include "stack.h"
#include <string.h>

int compareOpen(char c){
    return c=='{'||c=='('||c=='[';
}

int compareClose(char c){
    return c=='}'||c=='('||c==']';
}

int trans(char c){
    if(c==')') return '(';
    if(c=='}') return '{';
    if(c==']') return '[';
}

int main(){
    char open[]="{[(";
    char close[]="}])";
    StackType stack;
    printf("Nhap cac ky tu ngoac: {}/()/[]\n");
    char s[20];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(compareOpen(s[i])){
            push(&stack,s[i]);
        }
        if(compareClose(s[i])){
            if(Empty_Stack(stack)){
                printf("Fail\n");
            }
            else if(pop(&stack)!=trans(s[i])){
                printf("Fail\n");
            }
        }
    }
    if(Empty_Stack(stack)){
        printf("TRUE\n");
    }
    else{
        printf("FAIL\n");
    }
    return 0;
}