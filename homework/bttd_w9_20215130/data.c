#include <stdio.h>
#include "data.h"

void showData(data_t data){
    printf("%-20s %-5d\n",data.word,data.fre);
}