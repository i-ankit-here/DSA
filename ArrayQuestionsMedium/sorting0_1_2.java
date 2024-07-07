public class sorting0_1_2{
    public static void swap(int[] arr,int i, int j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public static void main(String[] args) {
        int [] arr = {1,1,2,1,2,0,1,2,0,1,2,0,1,0,2,1,0,2,0,1,0,1,2,0,1,0,2,1,0,2,0,1,0,2,1};
        int low=0;
        int med=0;
        int high=arr.length;
        while(med<high){
            if(arr[med]==0){
                swap(arr,low,med);
                low++;
            }else if(arr[med]==1){med++;}
            else if(arr[med]==2){
                System.out.println(arr[med]+" "+arr[high-1]);
                swap(arr,med,high-1);
                System.out.println(arr[med]+" "+arr[high-1]);
                high--;
            }
        }
    }
}
