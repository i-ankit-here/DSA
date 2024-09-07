using namespace std;
#include "iostream"

class Node{
public:
    int val;
    Node *next;
};

class Stack{
    private:
        static int max;
        int counter=0;
        Node *head = NULL;
    public:
        void push(int num){
            if(this->counter>max-1){
                cout<<"OVERFLOW !!"<<endl;
                return;
            }
            Node *temp = new Node;
            temp->val = num;
            temp->next = this->head;
            this->head = temp;
            counter++;            
        }
        void pop(){
            if(counter==0){
                cout<<"UNDERFLOW !!"<<endl;
                return;
            }
            cout<<head->val<<endl;
            Node* temp = head;
            head=head->next;
            temp->next = NULL;
            delete temp;
            counter--;
        }
};
int Stack::max=10;

int main(int argc, char const *argv[])
{
    Stack s;
    for(int i = 10; i<20;i++)s.push(i);
    for(int i = 0; i<10;i++)s.pop();
    return 0;
}
