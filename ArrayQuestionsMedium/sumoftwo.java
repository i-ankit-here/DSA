public class sumoftwo {
    // *********BRUTE FORCE SOLUTION*****************
    // public static void main(String[] args) {
    //     int[] arr = {1,3,4,5,6,3,4,5,2,4,2};
    //     int target = 10;
    //     for(int i = 0; i<arr.length;i++ ){
    //         for(int j = 0; j<arr.length;j++ ){
    //             if(i==j){
    //                 continue;
    //             }else if((arr[i]+arr[j])==target){
    //                 System.out.println(i+" "+j);
    //                 break;
    //             }else{
    //                 continue;
    //             }
    //         }
    //     } 
    // }
    public static void main(String[] args) {
        int[] arr = {1,3,4,5,6,3,4,5,2,4,2};
        int target = 10;
        for(int i = 0; i<arr.length;i++ ){
            for(int j = 0; j<arr.length;j++ ){
                if(i==j){
                    continue;
                }else if((arr[i]+arr[j])==target){
                    System.out.println(i+" "+j);
                    break;
                }else{
                    continue;
                }
            }
        } 
    }
}
