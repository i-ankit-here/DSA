#include "iostream"
using namespace std;
class header;
class Node
{
    int data;
    Node *next;
    friend class header;
public:
    Node(){
        this->data = INT_MAX;
        this->next = NULL;
    }
    Node(int num){
        this->data = num;
        this->next = nullptr;
    }
};

class header
{
    Node *head;
public:
    header(){
        head=new Node();
    }
    void add(int num){
        Node* temp = new Node(num);
        Node* temp1 = this->head->next;
        if(temp1==NULL){
            this->head->next = temp;
            return;
        }
        this->head->next = temp;
        temp->next = temp1;
    }
    void display(){
        Node* temp = this->head->next;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

};

int main()
{
    header h;
    h.add(1);
    h.add(2);
    h.add(3);
    h.add(4);
    h.display();
    return 0;
}