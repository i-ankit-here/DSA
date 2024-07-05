import java.util.Scanner;

public class pattern6 {
    public static void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = n; j>=i; j--) {
                System.out.print(n-j+1+" ");
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int num = in.nextInt();
        pattern(num);
    }
}
