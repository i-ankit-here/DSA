#include "iostream"
using namespace std;

class Node{
    int val;
    Node* next;
    friend class List;
    public:
    Node(){
        this->val = 0;
        this->next = nullptr;
    }
    Node(int num){
        this->val = num;
        this->next = nullptr;
    }
};

class List{
    Node* head;
    public:
    List(){
        this->head = nullptr;
    }
    void add(int num){
        Node* h = this->head;
        Node* temp = new Node(num);
        if(h==nullptr){
            this->head = temp;
            return;
        }
        while(h->next!=nullptr)h = h->next;
        h->next = temp;
    }

    void add(int num, int index){
        Node* h = this->head;
        Node* temp = new Node(num);
        if(index == 0){
            temp->next = this->head;
            this->head = temp;
            return;
        }
        for(int i=0;i<index-1;i++)h=h->next;
        temp->next = h->next;
        h->next = temp;
    }
    void display(){
        Node* temp = this->head;
        while(temp!=nullptr){
            cout<<temp->val<<"   ";
            temp=temp->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    List l;
    for(int i = 0;i<10;i++)l.add(i+1);
    l.add(5,4);
    l.display();
    return 0;
}
