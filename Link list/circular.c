#include "stdio.h"
#include "stdlib.h"

typedef struct student{
    int data;
    struct student* next;
} stu;

void createList(stu * head,int n){
    stu* temp1;
    temp1 = head;
    for(int i=0;i<n;i++){
        stu* temp;
        temp = (stu*) malloc(sizeof(stu));
        temp->data = n-i;
        temp->next = temp1;
        temp1=temp;
    }
    head->next=temp1;
}

void displayList(stu* head){
    int n=0;
    while(head->next != NULL){
        if(n==49)break;
        if(n%10==0){
           printf("\n"); 
        }
        printf("%d  ",head->data);
        head=head->next;
        n++;
    }
    printf("%d \n",head->data);
}

int main(){
    stu * head;
    head = (stu*) malloc(sizeof(stu));
    head->data=0;
    head->next=NULL;
    stu* temp;
    temp = head;
    createList(temp,9);
    displayList(temp);
    
}