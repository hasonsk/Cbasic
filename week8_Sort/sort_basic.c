#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insert_Sort(int a[],int n){
    int i,j, next;
    for(i = 1;i<n;i++){
        next=a[i];
        for(j=i-1;j>=0&&next<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=next;
    }
}

void Selection_Sort(int a[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(&a[i],&a[min]);
    }
}



int main(){
    int a[6]={6,2,4,3,5,1};
    Selection_Sort(a,6);
    for(int i=0;i<6;i++)
        printf("%d ",a[i]);
    return 0;
}