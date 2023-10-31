#include <stdio.h>
#include <string.h>
#include "data_t.h"

void swap(data_t *a, data_t *b){
    data_t temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int searchMoveToFront(data_t *A,int n, char name_find[]){
    int i,j;
    data_t temp;
    for(i=0;i<n;i++){
        if((strcmp(A[i].name,name_find)==0)){
            if(i>0){
                temp=A[i];
                for(j=0;j<i;j++)
                    swap(&A[j],&A[j+1]);
                A[0]=temp;
            }
            return i;
        }
    }
    return -1;
}


int main(){
    FILE *fin,*fout=fopen("output.dat","w+");
    if((fin=fopen("test.dat","r"))==NULL){
        perror("Can not access to File!\n");
        fclose(fin);
        return -1;
    }
    data_t A[100];
    int cnt=0;
    data_t temp;
    char name_find[30];
    while (fscanf(fin,"%s %s %s\n",A[cnt].name,A[cnt].tel,A[cnt].email)!=EOF)
    {
        showData(A[cnt]);
        cnt++;
    }
    printf("Enter name want to search: ");scanf("%s",name_find);
    int index=searchMoveToFront(A,cnt,name_find);
    printf("%d\n",index);
    if(index!=-1){
        int i=0;
        while(i<cnt){
            showData(A[i]);
            fprintf(fout,"%s-%s-%s\n",A[cnt].name,A[cnt].tel,A[cnt].email);
            i++;
        }
    }
    else{
        printf("No result for %s!\n\n\n",name_find);
    }
    fclose(fin);
    fclose(fout);
    
}