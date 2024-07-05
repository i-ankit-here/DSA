import java.util.Scanner;
public class pattern5 {
    public static void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= 4; j++) {
                System.out.print("* ");
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