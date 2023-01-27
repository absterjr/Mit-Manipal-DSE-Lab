import java.util.Scanner;
import java.util.Arrays;
public class Matrix_Mult {
	Scanner sc = new Scanner(System.in);
	public int r1, r2, c1, c2;
	int [][]mat1 = new int[100][100];
	int [][]mat2 = new int[100][100];
	    int [][]prod = new int[100][100];
	public
	    void getmat(){
	    System.out.println("Enter the no. of rows in the first matrix: ");
	    r1 = sc.nextInt();
	    System.out.println("Enter the no. of columns in the first matrix: ");
	    c1 = sc.nextInt();
	    System.out.println("Enter the no. of rows in the second matrix: ");
	    r2 = sc.nextInt();
	    System.out.println("Enter the no. of columns in the second matrix: ");
	    c2 = sc.nextInt();
	    System.out.println("Enter the elements of the first matrix");
	    for(int i=0; i<r1; i++){
	        for(int j=0; j<c1; j++){
	            mat1[i][j]=sc.nextInt();
	        }
	    }
	    System.out.println("Enter the elements of the second matrix");
	    for(int i=0; i<r2; i++){
	        for(int j=0; j<c2; j++){
	            mat2[i][j]=sc.nextInt();
	        }
	    }
	}
	void getprod(){

	    for(int i=0; i<r1; i++){
	        for(int j=0; j<c2; j++) {
	            for (int k = 0; k < r2; k++) {
	                prod[i][j] += mat1[i][k] *  mat2[k][j];
	            }
	        }
	    }
	}
	void disp(){

	    System.out.println("The resultant matrix is: ");
	    for(int i=0; i<r1; i++){
	        for(int j=0; j<c2; j++){
	            System.out.print(prod[i][j]+ " ");
	        }
	        System.out.print("\n");
	    }
	}
	public static void main(String []args){
	    Scanner sc = new Scanner(System.in);
	    Matrix_Mult obj = new Matrix_Mult();
	    obj.getmat();
	    obj.getprod();
	    obj.disp();
	}
}
	
