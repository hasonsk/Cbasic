#include "queue.h"
#include <stdio.h>
int main() {
   QueueType q;
   CreateQueue(&q);
   for (int i = 0; i < 10; i++) EnQueue(&q,i);
   for (int i = 0; i < 10; i++) {
      int t = DeQueue(&q);
      printf("%d ", t);
   }

   return 0;
}