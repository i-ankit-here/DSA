public class solution {
    static int pos(int n) {
        return n > 0 ? n : -n;
    }

    static int divide(int dividend, int divisor) {
        int ans = 0;
        int sign = 0;
        if (dividend < 0 && divisor < 0)
            sign = 0;
        else if (dividend < 0 || divisor < 0)
            sign = 1;
        else
            sign = 0;
        dividend = pos(dividend);
        divisor = pos(divisor);
        if(dividend<0){
            dividend=pos(dividend+divisor);
            ans++;
        }
        System.out.println(dividend+" "+divisor+" "+ans);
        while (dividend >= divisor) {
            if(ans>=Integer.MAX_VALUE){
                return sign == 0 ?Integer.MAX_VALUE:Integer.MIN_VALUE;
            }
            dividend-=divisor;
            ans++;
        }
        return sign == 0 ? ans : -1 * ans;
    }

    public static void main(String[] args) {
        
        // System.out.println(pos(-2147483648+1));
        System.out.println(divide(-2147483648, 2));
    }
}