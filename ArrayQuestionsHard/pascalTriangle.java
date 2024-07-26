public class pascalTriangle {
    static int max(int num1 , int num2){return num1>num2?num1:num2;}
    // public static void main(String[] args) {
    //     // get a particular element with given row and column
    //     //     1
    //     //    1 1
    //     //   1 2 1
    //     //  1 3 3 1 
    //     // 1 4 6 4 1
    //     //1 5 10 10 5 1
        
    //     // Formula : (row-1)C(col-1)
    //     int r = 5;//Assuming row-1 to be r
    //     int c = 3;//Assuming col-1 to be c
    //     int result = 1;
    //     for(int i = 0;i<max(c,r-c);i++){
    //         result = result * (r-i);
    //         result = result/(i+1);
    //     }
    //     System.out.println(result );
    // }
    public static void main(String[] args) {
        // get a particular element with given row and column
        //     1                                     1  4x3x2x1/1x1x2x3x4
        //    1 1                                    4  4/1  
        //   1 2 1                                   6  4x3/2x1
        //  1 3 3 1                                  4  4x3x2/3x2x1
        // 1 4 6 4 1                                 1  4x3x2x1/
        //1 5 10 10 5 1   
        
        // Formula : (row-1)C(col-1)
        int n = 6;
        int result = 1;
        for(int i = 0;i<n;i++){
            if(i==0 || i==n-1){
                System.out.print(1+" ");
            }else{
                result = result*(n-i);
                result = result/i;
                System.out.print(result+" ");
            }

            
        }
        
    }
}
