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
    for (int i = 0; i < 10; i++)
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
    Node *prev,*curr;
    prev = NULL;
    curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;    
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