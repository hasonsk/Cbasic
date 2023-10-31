#include <stdio.h>
#include <string.h>
#include "data_t.h"

void showData(data_t data){
    printf("%s - %s - %s\n",data.name,data.tel,data.email);
}

data_t createData(){
    data_t newData;
    fflush(stdin);
    printf("Enter name: "); fgets(newData.name,30,stdin);    newData.name[strlen(newData.name)-1]='\0';
    printf("Enter telephone: "); scanf("%s",newData.tel);
    printf("Enter email: "); scanf("%s",newData.email);
    return newData; 
}