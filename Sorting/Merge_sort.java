public class Merge_sort{
    static void merge(int[] arr,int low,int mid,int high){
        int[] temp= new int[high-low+1];
        int j=low;
        int k=mid+1;
        int i=0;
        while(j<=mid && k<=high){
            if (arr[j]<=arr[k]){
                temp[i]=arr[j];
                i++;
                j++;
            }
            else{
                temp[i]=arr[k];
                i++;
                k++;
            }
        }
        while(j<=mid){
            temp[i]=arr[j];
            j++;
            i++;
        }
        while(k<=high){
            temp[i]=arr[k];
            k++;
            i++;
        }
        for(int g=0;g<temp.length;g++){
            arr[low+g]=temp[g];
        }
    }
    static void merge_sort(int[] arr,int low,int high){
        if(low>=high){
            return;
        }
        int mid=(high+low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    public static void main(String[] args) {
        int[] ar={4 ,1 ,3 ,9 ,7};
        merge_sort(ar,0,ar.length-1);
        for(int i=0;i<ar.length;i++){
            System.out.print(ar[i]+" ");
        }
    }
}