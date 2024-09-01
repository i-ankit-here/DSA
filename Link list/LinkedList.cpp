#include "iostream"
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class header
{
public:
    int count;
    Node *head;
};

void createList(Node *head)
{
    Node *temp1;
    temp1 = head;
    for (int i = 0; i < 1; i++)
    {
        Node *temp;
        temp = new Node;
        temp->data = i;
        temp->next = NULL;
        temp1->next = temp;
        temp1 = temp;
    }
}

Node* reverseList(Node * head){
    Node *prev,*curr,*nex;
    prev = head;
    curr = prev->next;
    nex = curr->next;
    while(curr->next!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr = nex;
    }
    curr->next = prev;
    head->next = NULL;
    return curr;    
}

void displayLsit(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    header *h;
    h=new header;    
    Node *head;
    head = new Node;
    head->data = 10;
    head->next = NULL;
    h->head=head;
    createList(h->head);
    displayLsit(h->head);
    cout<<endl;
    displayLsit(h->head);
    cout<<endl;
    displayLsit(h->head);
    cout<<endl;
    h->head=reverseList(h->head);
    displayLsit(h->head);
    return 0;
}