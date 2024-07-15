public class count_subarrays_with_given_sum {

    //BRUTE FORCE SOLUTION for count of subarrays with given sum
    // public static void main(String[] args) {
    //     int[] arr = {1,2,1,1,1,1,3,4,1,2};
    //     int count =0;
    //     int k = 3;// can  take as input
    //     for(int i = 0;i<arr.length;i++){
    //         for(int j = i;j<arr.length;j++){
    //             int sum =0;
    //             for(int l = i;l<=j; l++){
    //                 sum+=arr[l];           
    //             }
    //             if(sum == k){
    //                 count++;
    //             }   
    //         }            
    //     }


    //     System.out.println(count);


    // }



    //BETTER SOLUTION
    public static void main(String[] args) {
        int[] arr = {1,2,1,1,1,1,3,4,1,2};
        int count =0;
        int k = 4;// can  take as input
        for(int i = 0;i<arr.length;i++){
            int sum =0;
            for(int j = i;j<arr.length;j++){
                sum+=arr[j]; 
                if(sum == k){
                    count++;
                }   
            }            
        }
    
    
        System.out.println(count);
    
    
    }
}
