import java.util.Scanner;
public class MaxLengthSubarrayForSum{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int [] arr = {1,1,1,1,1,1,1,1};
        System.out.printf("Target of the sum: ");
        int k = in.nextInt();
        int [] hash = new int[8];
        int sum = 0;
        int maxLength=0;
        for(int i=0;i<8;i++){
            sum+=arr[i];
            hash[i]=sum;
            if(sum==k){
                maxLength=i+1;
            }
            for(int j=0;j<=i;j++){
                if((sum-hash[j])==k && (i-j)>maxLength){
                    maxLength=i-j;
                    break;
                }
            }
        }
        System.out.println(maxLength);
    }
}