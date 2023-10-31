#ifndef __DATA_H__
#define __DATA_H__

typedef struct 
{
    char word[20];
    int fre;  //frequency
}data_t;

void showData(data_t data);
#endif