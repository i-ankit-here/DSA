using namespace std;
#include "iostream"

class Node
{
    int data;

public:
    Node *next;
    Node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
    Node(int num, Node *node)
    {
        this->data = num;
        this->next = node;
    }
    int show() { return this->data; }
};

class Linklist
{
    Node *head;

public:
    Linklist()
    {
        this->head = NULL;
    }
    void insertAtBeginning(int num)
    {
        Node *newNode = new Node(num, this->head);
        this->head = newNode;
    }
    void displayList()
    {
        Node *temp = this->head;
        while (temp->next != NULL)
        {
            cout << temp->show() << "  ";
            temp = temp->next;
        }
        cout << temp->show();
    }
    Node *KthLargest(int k)
    {
        Node *prev = new Node(INT_MAX);
        while (k > 0)
        {
            Node *max = new Node(INT_MIN);
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                if (temp->show() > max->show() && temp->show()<prev->show())
                {
                    max = temp;
                }
                temp = temp->next;
            }
            if (temp->show() > max->show() && temp->show()<prev->show())
            {
                max = temp;
            }
            prev = max;
            k--;
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    Linklist *list = new Linklist();
    list->insertAtBeginning(5);
    list->insertAtBeginning(4);
    list->insertAtBeginning(3);
    list->insertAtBeginning(2);
    list->insertAtBeginning(1);
    list->displayList();
    Node *k_max = list->KthLargest(3);
    cout << endl;
    cout << k_max->show() << endl;
    return 0;
}
