import java.util.Scanner;
public class pattern8 {
    public static void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<=n-i; j++) {
                System.out.print(" ");
            }
            for (int l = 1; l<=2*i-1; l++) {
                System.out.print("*");
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