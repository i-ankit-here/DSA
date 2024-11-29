#include "iostream"
using namespace std;
class minheap{
    int arr[100]={0};
    int i;
    public:
    minheap(){
        i = 0;
    }
    void insert(int num){
        arr[i] = num;
        for(int j = i;(j-1)/2>=0;j = (j-1)/2){
            if(j==0)break;
            if(arr[j]>arr[(j-1)/2])break;
            arr[j] = arr[j]^arr[(j-1)/2];
            arr[(j-1)/2] = arr[j]^arr[(j-1)/2];
            arr[j] = arr[j]^arr[(j-1)/2];
        }
        i++;
    }
    int del(){
        if(i == 0)return -1;
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = 0;
        // show();
        i--;
        for(int j = 0;;){
            int n = arr[2*j+1]>arr[2*j+2]?2*j+2:2*j+1; 
            if(2*j+1>=i)break;
            if(2*j+1==i-1)n=2*j+1;
            if(arr[j]<arr[n])break;
            arr[j] = arr[j]^arr[n];
            arr[n] = arr[j]^arr[n];
            arr[j] = arr[j]^arr[n];
        }
        return temp;
    }
    void heapify(int nums[],int n,int i){
        int j = i;
        for(j;j>=0;j--){
            int min = j;
            if((2*j + 1<n) && nums[min]>nums[2*j + 1])min = 2*j+1;
            if((2*j + 2<n) && nums[min]>nums[2*j + 2])min = 2*j+2;
            if(j!=min){
                nums[j] = nums[j]^nums[min];
                nums[min] = nums[j]^nums[min];
                nums[j] = nums[j]^nums[min];
                heapify(nums,n,min);
            }
        }
    }
    void show(){
        for (int j = 0; j < i-1+1; j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
};
int main(int argc, char const *argv[])
{
    minheap h;
    h.insert(3);
    h.show();
    h.insert(2);
    h.show();
    h.insert(1);
    h.show();
    h.insert(4);
    h.show();
    for(int i = 0;i<4;i++){cout<<h.del()<<"              ";h.show();}
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j = n/2 - 1;
    h.heapify(arr,n,j);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}