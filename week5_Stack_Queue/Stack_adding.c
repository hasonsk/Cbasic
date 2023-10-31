//Ha Hong Son 20215130
//Cong hai so nguyen su dưng Stack

#include <stdio.h>
#include "stack.h"

//Nhap so nguyen tu ban phim
void enterNumber(StackType *pStack){
    char c='\0';
    while(scanf("%c",&c)){
        if(c=='\n') break;
        push(pStack,c-'0');
    }
}
//Tinh tong 2 so nguyen
void Sum(StackType num1,StackType num2){
    StackType result;
    CreateStack(&result);     
    int remain=0;
    short int tmp; 
    int e1,e2;  //chữ số hàng (đơn vị, chục, trăm,..) cua num1, num2
    while(!Empty_Stack(num1)||!Empty_Stack(num2)){
        if(!Empty_Stack(num1))
             e1=pop(&num1);
        else e1=0;
        if(!Empty_Stack(num2))
              e2=pop(&num2);
        else  e2=0;
        tmp=e1+e2+remain;
        if(tmp>9){
            remain=1;
            tmp-=10;
        }
        else{
            remain=0;
        }
        push(&result,tmp);//thêm vào result 
    }
    if(remain==1)
       push(&result,1);
    while(!Empty_Stack(result)){
        tmp=pop(&result);
        printf("%d",tmp);
    }
    printf("\n");
}

int main(){
    StackType num1,num2;
    CreateStack(&num1);CreateStack(&num2);
    printf("Enter the first number:\n");
    enterNumber(&num1);
    printf("Enter the second number:\n");
    enterNumber(&num2);
    Sum(num1,num2);
    return 0;
}