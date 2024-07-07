public class sorting0_1_2{
    public static void swap(int[] arr,int i, int j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public static void main(String[] args) {
        int [] arr = {0,1,2,1,2,0,1,2,0,1,2,0,1,0,2,1,0,2,0,1,0,1,2,0,1,0,2,1,0,2,0,1,0,2,1};
        int low=0;
        int mid=0;
        int high=arr.length;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr,low,mid);
                low++; 
                mid++;
            }else if(arr[mid]==1){mid++;}
            else if(arr[mid]==2){
                swap(arr,mid,high-1);
                high--;
            }
        }
        // for(int i : arr){System.out.print(i+" ");}
    }
}
