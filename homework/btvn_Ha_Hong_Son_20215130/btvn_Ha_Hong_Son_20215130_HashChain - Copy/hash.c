/*
    Hạ Hồng Sơn - 20215130
*/

#include "hash.h"

#include <string.h>

element_t *D[TABLE_SIZE];  // <===

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t *ht[]) {  // <===
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int b) {
  // your code here
  element_t* p  =NULL;
  for(; ht[b] != NULL; ht[b] = p){
      p = ht[b]->next;
      free(ht[b]);
  }
}

element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  else  // Traverse through the list at bucket H(X)
    // your code here
  {
    element_t *p = ht[hash_value];
    while(p != NULL){
        if (strcmp(p->key, key) == 0 )
            return p; //found
        p = p->next;
    }
    return NULL;   //Not found  
  }
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    // your code here
    if(findElement(ht, o.key) != NULL) {
        printf("Da co %s trong bang!\n", o.key);   //phan tu da ton tai, khong cho them vao
        return FALSE;
    }
    pNewElement->next = ht[hash_value];
    ht[hash_value] = pNewElement;
    return TRUE;
  }
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *p1 = ht[hash_value];

  if (p1 == NULL)
    return -1;  // khong tim thay
  else {
    // your code here
    while (p1 != NULL) {
        if (strcmp(p1->next->key, key) == 0){
            element_t *pNode = p1->next;
            p1->next = pNode->next;
            free(pNode);
            return TRUE;
        }
        p1 = p1->next;  
    }
    return -1;   //Not found 
  }
}

int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
};

void _traversebucket(element_t *ht[], int b) {
  // your code here
  if(ht[b] == NULL) return;
  element_t *p = ht[b];
  while (p != NULL) {
      printf("\"%s\"  \"%s\"\n",p->key, p->word);
      p = p->next;
  }
  free(p);
}

void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d\n", b);
    _traversebucket(ht, b);
  }
}
