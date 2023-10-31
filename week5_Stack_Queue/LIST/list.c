#include <stdio.h>
#include <stdlib.h>
typedef int item_type;

typedef struct list
{
    item_type
 item;
    struct list *next;
}list;

list *createList(item_type item){
    list *new_list;
    new_list=(list*)malloc(sizeof(list));
    new_list->item=item;
    new_list->next=NULL;
    return new_list;
}

list *search_list(list *l, item_type x){
    if(l==NULL) return NULL;
    if(l->item==x)
      return (l);
    else
      return (search_list(l->next,x));
}

void show_list(list *l){
    if(l==NULL){
        printf("No item to show!\n");
        return;
    }
    while(l->next!=NULL){
        printf("%d ",l->item);
        l=l->next;
    }
    return;
}

void insert_list(list **l, item_type x){
    list *p;
    p=createList(x);
    p->next=*l;
    *l=p;
}

//Deletion From a List
list *predecessor_list(list *l, item_type x){
    if(l==NULL||l->next==NULL){
        printf("Error: prodecessor sought on null list.]n");
        return (NULL);
    }
    if((l->next)->item==x)
        return (l);
    else 
        return (predecessor_list(l->next,x));
}

void delete_list(list **l, item_type x){
    list *p;
    list *pred; //predecessor pointer
    p = search_list(*l,x);
    if(p!=NULL){
        pred=predecessor_list(*l,x);
        if(pred==NULL)
            *l=p->next;
        else
            pred->next=p->next;
        free(p);
    }
}

void delete_all_list(list **l){
    list *p;
    for(p=*l;*l!=NULL;*l=p->next){
        free(*l);
        p=p->next;
    }
    show_list(*l);
}


int main(){
    list *l;
    item_type n;
    l=createList(0);
    insert_list(&l,10);
    insert_list(&l,20);
    insert_list(&l,30);
    insert_list(&l,40);
    show_list(l);
    printf("Enter item want delete: "); scanf("%d",&n);
    delete_list(&l,n);
    show_list(l);
    delete_all_list(&l);

}