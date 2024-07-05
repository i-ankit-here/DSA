public class Quick_sort {
    static int partition(int[] arr,int low,int high){
        int pivot =arr[low];
        int i=low;
        int j=high;
        while (i<j) {
            while((arr[i]<=pivot) && (i<high)){
                i++;
            }
            while((arr[j]>=pivot) && (j>low)){
                j--;
            }
            if(i<j){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        int temp=arr[j];
        arr[j]=arr[low];
        arr[low]=temp;
        return j;        
    }
    static void quick(int[] arr,int low,int high){
        if(low<high){
            int index=partition(arr, low, high);
            quick(arr,low,index-1);
            quick(arr,index+1,high);
            return;
        }
    }
    public static void main(String[] args) {
        int[] s={23424,354,3,56,64,7778,86,68,6,64,34324,234,234,213,213,213,132,234,324,3445676,667,75534,32,312,132,132,23,324354};
        quick(s,0, s.length-1);
        for (int i : s) {
            System.out.print(i+" ");            
        }
    }
}
