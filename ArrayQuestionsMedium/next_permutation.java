public class next_permutation {
    static void swap(int[] arr , int bigger , int breakPoint){
        arr[breakPoint]=arr[breakPoint]^arr[bigger];
        arr[bigger]=arr[breakPoint]^arr[bigger];
        arr[breakPoint]=arr[breakPoint]^arr[bigger];
    }
    static void reverse(int[] arr , int start, int end){
        while(start<end){
            swap(arr,start,end);
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9,0};
        int breakPoint = -1;
        int bigger = -1;
        for (int i = arr.length-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                breakPoint = i;
                break;
            }
        }
        if(breakPoint==-1){
            reverse(arr, 0, arr.length-1);
        }else{
            for(int i = arr.length-1;i>breakPoint;i--){
                if(arr[i]>arr[breakPoint]){
                    bigger = i;
                    break;
                }
            }
            swap(arr,breakPoint,bigger);
            reverse(arr,breakPoint+1,arr.length-1);
        }
        for(int i:arr){
            System.out.print(i+" ");
        }
        
    }
}
