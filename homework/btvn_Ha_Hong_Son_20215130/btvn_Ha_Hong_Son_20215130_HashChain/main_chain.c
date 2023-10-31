#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

element_t* ht[TABLE_SIZE];

int main() {
  const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee"};
  // const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe"};
  // const char* keys[] = {"Lisa Smith", "Sandra Dee"};

  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(key, hash(key)) = (%d, %s)\n", hash(keys[i]), keys[i]);
  }

  init_table(ht);
  int n;
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }

  printf("Traverse:\n");
  traverse(ht);

  element_t e1 = {"Lisa Smith", "CNTT Viet Nhat", NULL};
  insertItem(ht, e1);
  removeElement(ht, "Lisa Smith");

  insertItem(ht, e1);

  printf("Traverse:\n");
  traverse(ht);

  clear(ht);
  return 0;
}