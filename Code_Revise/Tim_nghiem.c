/*
    Hãy cho biết số nghiệm nguyên dương của phương trình
      2x1 + 4x2 + 3x3 + 5x4 = 60
    thỏa mãn điều kiện x1 + x2 = 6
*/

#include <stdio.h>

int a[5]={0,2,4,3,5};  //cac he so tuong ung
int S=60;
int x[5];
int g;

void Ghinhan(){
    static int count=0;
    ++count;
    printf("%d. ",count);
    for(int i=1;i<=4;i++)
       printf("%d ",x[i]);
    printf("\n");
}


void Try(int k){
    if(k>4||S<0) return;
    for(int i=1;i<25;i++){
        x[k]=i;
        //printf("%d %d \n",k,x[k]);
        S-=a[k]*x[k];
        //if(k==4) printf("\n");
        if(k==4&&S==0&&(x[1]+x[2]==6)) Ghinhan();
        if(k==3&&S%a[4]!=0){
            S+=a[k]*x[k];
            return ;
        }
        Try(k+1);
        S+=a[k]*x[k];
    }
}


int main(){
    Try(1);
}