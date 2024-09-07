using namespace std;
#include "iostream"

class Stack{
    private:
        static int max;
        int counter=0;
        int arr[10];
    public:
        void push(int num){
            if(counter>max-1){
                cout<<"OVERFLOW !!"<<endl;
                return;
            }
            // cout<<this->counter<<"   "<<num<<endl;
            this->arr[counter++]=num;
        }
        void pop(){
            if(counter==0){
                cout<<"UNDERFLOW !!"<<endl;
                return;
            }
            cout<<this->arr[--counter]<<endl;
        }
};
int Stack::max=10;

int main(int argc, char const *argv[])
{
    Stack s;
    for(int i = 10; i<20;i++)s.push(i);
    for(int i = 0; i<=10;i++)s.pop();
    return 0;
}
