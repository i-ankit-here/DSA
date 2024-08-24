#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct firstLinkedList
{
    int value;
    char name[10];
    struct firstLinkedList * next;
};

struct firstLinkedList * createList(struct firstLinkedList * head, int n ){
    for(int i = n;i>0;i--){
        struct firstLinkedList* temp;
        temp = (struct firstLinkedList *)malloc(sizeof(struct firstLinkedList));
        temp->value = i;
        char n[10]={'a','n','k','i','t','\0'};
        strcpy(temp->name,n);
        temp->next = head;
        head = temp;
    }
    return head;
}
void main(){
    struct firstLinkedList* head;
    head = (struct firstLinkedList *)malloc(sizeof(struct firstLinkedList));
    head->value=10;
    strcpy(head->name,"ankit0");
    head = createList(head,15);
    for(int i = 15;i>0;i--){
        printf("%d  %s\n",head->value,head->name);
        head=head->next;
    }
}