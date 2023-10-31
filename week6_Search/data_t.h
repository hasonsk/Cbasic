#ifndef __DATA_T_H__
#define __DATA_T_H__

#include <stdio.h>

typedef struct
{
    char name[30];
    char tel[20];
    char email[30];
}data_t;
void showData(data_t data);
data_t createData();
#endif 