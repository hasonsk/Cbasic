#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "data.h"
#include "bst.h"

void putFile(FILE *fout,tree_t root){
    if(root!=NULL){
        putFile(fout,root->left);
        fprintf(fout,"%-20s%-5d\n",root->data.word,root->data.fre);
        putFile(fout,root->right);
    }
}


int main(int argv, char *argc[]){
    if(argv!=3){
        printf("NOT SUITABLE!\n");
        return EXIT_FAILURE;
    }
    //Kiem tra file dau vao, dau ra
    FILE *fin, *fout;
    if((fin=fopen(argc[1],"r"))==NULL){
        perror("Cannot open file input!\n");
        fclose(fin);
        return EXIT_FAILURE;
    } 
    else if((fout=fopen(argc[2],"w+")) == NULL){
        perror("Cannot open file output!\n");
        fclose(fin);
        fclose(fout);
        return EXIT_FAILURE;
    }

    tree_t root = NULL;
    tree_t p;
    char c;
    int i;
    char s[20];
    while((c=fgetc(fin)) != EOF){  
        if(isalnum(c)){
            i = 0;
            while (isalnum(c)){
                c = toupper(c);
                s[i] = c;
                c = fgetc(fin);
                i++;
            }
            p = searchNode(s,root);
            if(p == NULL){
                insertNode(s, &(root));
            }
            else 
                p->data.fre +=1;
            strncpy(s, "", strlen(s));
        }
    }

    putFile(fout,root);  //Ghi vao FILE
    travesal(root);      //Ghi ra man hinh 

    freeTree(&root);   
    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}
