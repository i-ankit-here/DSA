import java.util.Arrays;

public class majority_element {
    // ************* BRUTE FORCE SOLUTION ******************************
    // Count frequence of each element and return if it is>N/2



    // ************* BETTER SOLUTION USING HASH ARRAY ******************
    // public static void main(String[] args) {
    //     int[] arr = {2,2,3,3,4,3,3,3,5,3,6,3,7,3,3};
    //     int[] hash = new int[100];
    //     Arrays.fill(hash, 0);
    //     for(int i=0;i<arr.length;i++){
    //         hash[arr[i]]+=1;
    //     }
    //     for(int i=0;i<hash.length;i++){
    //         if(hash[i]>(arr.length/2)){System.out.println(i);break;}
    //     }
    // }


    // ******************** OPTIMAL SOLUTION ***************************
    // Case when the majority element is always present
    // when it is not we need to use an extra loop to count the frequeny of elem at last and return it if is (>N/2)
    public static void main(String[] args) {
        int[] arr = {2,2,3,3,4,3,3,3,5,3,6,3,7,3,3};
        int count =0;
        int elem = arr[0];
        for (int i = 0;i< arr.length; i++){
            if(elem == arr[i]){
                count++;
            }
            else{
                count--;
            }
            if(count<=0){
                elem=arr[i+1];
            }
        }
        System.out.println(elem);
        
    }
}
