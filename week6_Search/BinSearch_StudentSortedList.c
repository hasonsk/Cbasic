/*
    Hạ Hồng Sơn - 20215130
    Date: 01.12.2022
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOT_FOUND (-1)


typedef struct 
{
    char id[20];
    char name[32];
    int grade;
} data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}*root_t, node;

/*============= Funtions of Link listed ============ */

node *llInit(){ return NULL;}

node *createNode(data_t data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void showData(data_t data){
    printf("%s %s %d\n",data.id,data.name,data.grade);
}

void llPrint(root_t lst){
    while(lst!=NULL){
        showData(lst->data);
        lst=lst->next;
    }
}

//Thêm vô đầu danh sách
root_t llInsertHead(root_t lst,data_t data){
    node *newnode=createNode(data);
    newnode->next=lst;
    lst=newnode;
    return lst;
}
//Trả về phần tử ở giữa danh sách
node *middle(node *head,node *tail){
    if(head==NULL) return NULL;
    node *low=head;         
    node *fast=head->next;   
    while(fast!=tail){
        fast=fast->next;
        if(fast!=tail){
            low=low->next;
            fast=fast->next;
        }
    }
    return low;
}

/*
Chương trình 1.
        a. Tạo một danh sách liên kết có thứ tự theo grade từ lớn đến nhỏ.
        b. Sử dụng tìm kiếm nhị phân, hãy viết hàm trả về con trỏ đến student tìm thấy, NULL nếu không tìm thấy có 
        prototype như sau (key là grade):
            data_t* binarySearchByGrade(root_t lst, const int key);
        c. Viết chương trình chính thử nghiệm
*/

data_t* binarySearchByGrade(root_t lst, const int key){
    node *head=lst;
    node *tail=NULL;
    node *mid=middle(head,tail);
    if(mid==NULL)   
        return NULL;
    while(tail!=head){
        node *mid=middle(head,tail);
        if(mid==NULL)
            return NULL;
        if(mid->data.grade==key)
            return &(mid->data);
        else if(mid->data.grade<key)
            head=mid->next;
        else
            tail=mid;
    }
    return NULL;
}

/*
Chương trình 2.
        a. Tạo danh sách liên kết có thứ tự theo name từ nhỏ đến lớn (theo alphabet)
        b. Sử dụng tìm kiếm nhị phân, hãy viết hàm trả về con trỏ đến student tìm thấy, NULL nếu không tìm thấy có 
        prototype như sau (key là name)
            data_t* binarySearchByName(root_t lst, char* key);
        c. Viết chương trình chính thử nghiệm các hàm
*/
data_t* binarySearchByName(root_t lst, const char name[]){
    node *head=lst;
    node *tail=NULL;
    node *mid=middle(head,tail);
    if(mid==NULL)
        return NULL;
    while(tail!=head){
        node *mid=middle(head,tail);
        if(mid==NULL)
            return NULL;
        if(strcmp(mid->data.name,name)==0)
            return &(mid->data);
        else if(strcmp(name , mid->data.name)>0)
            head=mid->next;
        else
            tail=mid;
    }
    return NULL;
}


int main(){
    data_t SV[]={
        {"001","sv1",2},
        {"002","sv2",3},
        {"003","sv3",4},
        {"004","sv4",5},
        {"005","sv5",7},
        {"006","sv6",9}
    };  //Tạo một danh sách liên kết có thứ tự theo grade từ lớn đến nhỏ.
        //Tạo danh sách liên kết có thứ tự theo name từ nhỏ đến lớn (theo alphabet)
    root_t lst = llInit();  //Khởi tạo lst = NULL
    for(int i=sizeof(SV)/sizeof(SV[0])-1;i>=0;i--){
        lst=llInsertHead(lst,SV[i]);
    }


    printf("\n\nPrint ALL!\n");
    llPrint(lst);


    int key = 4;
    char name[]="sv5";
    data_t *pStudent;

    //Viết chương trình chính thử nghiệm
    pStudent = binarySearchByGrade(lst,key);
    if(pStudent==NULL) printf("Khong tim thay!\n");
    else{
        printf("Student have %d grade:\n",key);
        showData(*pStudent);
    }

    //Viết chương trình chính thử nghiệm
    pStudent = binarySearchByName(lst,name);
    if(pStudent==NULL) printf("Khong tim thay!\n");
    else{
        printf("Student have name \"%s\":\n",name);
        showData(*pStudent);
    }
    return 0;
}