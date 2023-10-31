#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct{
  char name[20], tel[20], email[32];
} data_t;

// Must Adapt to new problem
void showData(data_t data);
void showAllData(data_t a[], int elemNbr);
// data_t convert(int i);

#endif