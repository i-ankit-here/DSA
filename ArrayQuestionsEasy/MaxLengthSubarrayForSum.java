import java.util.Scanner;

public class MaxLengthSubarrayForSum {
    // ******** BETTER SOLUTION (For positive integers and OPTIMAL for positive and negative integers)***************
    // public static void main(String[] args) {
    // Scanner in = new Scanner(System.in);
    // int [] arr = {0,1,1,0,1,1,1};
    // System.out.printf("Target of the sum: ");
    // int k = in.nextInt();
    // int [] hash = new int[arr.length];
    // int sum = 0;
    // int maxLength=0;
    // for(int i=0;i<arr.length;i++){
    // sum+=arr[i];
    // hash[i]=sum;
    // if(sum==k){
    // maxLength=i+1;
    // }
    // for(int j=0;j<=i;j++){
    // if((sum-hash[j])==k && (i-j)>maxLength){
    // maxLength=i-j;
    // break;
    // }
    // }
    // }
    // System.out.println(maxLength);
    // }

    // ************** OPTIMAL SOLUTION (For positive integers) ******************
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = { 0, 1, 1, 0, 1, 1, 1 };
        System.out.printf("Target of the sum: ");
        int k = in.nextInt();
        // int [] hash = new int[arr.length];
        int sum = arr[0];
        int maxLength = 0;
        int j = 0;
        int i = 0;
        while (i < arr.length) {
            while(j<=i && sum > k){
                sum -= arr[j];
                j++;
            }
            if(sum==k){maxLength=maxLength<(i-j+1)?(i-j+1) : maxLength;}
            i++;
            if(sum<=k && i < arr.length){sum+=arr[i];}
        }
        System.out.println(maxLength);
    }
}