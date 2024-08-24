#include "stdio.h"
#include "stdlib.h"

typedef struct student{
    int value;
    struct student* next;
    struct student* prev;
}stu;

void createList(stu* head,int n){
    for(int i = 0;i<n;i++){
        stu* temp;
        temp = (stu*)malloc(sizeof(stu));
        temp->value=i;
        temp->next=NULL;
        temp->prev=NULL;
        temp->prev=head;
        head->next=temp;
        head = temp;
    }
}

void displayList(stu * head){
    while(head->next != NULL){
        printf("%d  ",head->value);
        head=head->next;
    }
    printf("%d",head->value);
    printf("\n");
    while(head->prev != NULL){
        printf("%d  ",head->value);
        head=head->prev;
    }
    printf("%d",head->value);
}

int main(){
    stu * head;
    head = (stu*)malloc(sizeof(stu));
    head->value=10;
    head->next=NULL;
    head->prev=NULL;

    stu * temp;
    temp=head;
    createList(temp,9);
    temp=head;
    displayList(temp);

    return 0;
}