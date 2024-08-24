#include "stdio.h"
#include "stdlib.h"

struct student {
    int value;
    struct student* next;
};

struct student * createList(struct student ** head , int n){
    for(int i = n-1;i>=0;i--){
        struct student *temp;
        temp = (struct student *) malloc(sizeof(struct student));
        temp->value = i;
        temp->next = *head;
        *head=temp;
    }
    return *head;
}
struct student * displayList(struct student * head){
    struct student * temp;
    temp = head;
    while(temp->next != NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("%d ",temp->value);
    printf("\n");
    return head;
}
struct student * insertStart(struct student * head,int n){
    struct student * temp;
    temp = (struct student *) malloc(sizeof(struct student));
    temp->value = n;
    temp->next = head;
    return temp;
}

struct student * insertLast(struct student * head,int n){
    struct student * t;
    t=head;
    struct student * temp;
    temp = (struct student *) malloc(sizeof(struct student));
    temp->value = n;
    temp->next=NULL;
    while(t->next!=NULL){
        // printf("%d",t);
        t=t->next;
    }
    t->next = temp;
    // printf("%d",t->next->value);
    return head;
}

struct student * insertAt(struct student * head,int index,int n){
    struct student * temp;
    temp = (struct student *) malloc(sizeof(struct student));
    temp->value = n;
    struct student * t;
    t=head;
    for(int i = 0;i<index-1;i++){
        t=t->next;
    }
    struct student * j = t->next;
    t->next = temp;
    temp->next = j;
    return head;
}

struct student * deleteNode(struct student* head,int num){
    struct student * temp;
    temp=head;
    struct student * prev=NULL;
    while(temp->next!=NULL){
        if(temp->value==num){
            if(prev==NULL){
                prev=head;
                head=head->next;
                temp=temp->next;
                prev->next=NULL;
                free(prev);
                break;
            }else{
                prev->next=temp->next;
                free(temp);
                break;
            }       
        }
        prev=temp;
        temp=temp->next;
    }
    if(temp->value==num && temp->next==NULL){
        prev->next=NULL;
        free(temp);
    }
    return head;
}

int main(){
    struct student * head;
    head = (struct student *) malloc(sizeof(struct student));
    head->value=10;
    head->next=NULL;
    struct student **temp;
    temp = &head;
    
    head = createList(temp , 10);
    head = displayList(head);
    // head = insertStart(head,-1);
    // head = displayList(head);
    // head = insertLast(head,11);
    // head = displayList(head);
    // head = insertAt(head,4,200);
    // head = displayList(head);
    head = deleteNode(head,10);
    head = displayList(head);
    return 0;
}