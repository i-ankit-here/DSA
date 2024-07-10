import  java.util.Arrays;
public class matrix_zeros {

    // Better Solution to Set row and column as Zeros when zero is encountered in the matrix 
    public static void main(String[] args) {
        int[][] matrix = {
                { 1, 1, 1, 1, 1 },
                { 1, 1, 0, 1, 1 },
                { 1, 1, 1, 1, 1 } 
            };
        int[] m = new int[matrix.length];
        Arrays.fill(m, 0);
        int[] n = new int[matrix[0].length];
        Arrays.fill(n, 0);

        for(int i = 0; i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    m[i]=1;
                    n[j]=1;
                }
            }
        }

        for(int i = 0; i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(m[i]==1 || n[j]==1){
                    matrix[i][j]=0;  
                }
            }
        }

        for(int i = 0; i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }

    }
}
