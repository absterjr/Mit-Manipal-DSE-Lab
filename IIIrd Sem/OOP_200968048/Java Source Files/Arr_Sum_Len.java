import java.util.Scanner;
import java.util.Arrays;
import java.util.InputMismatchException;
public class Arr_Sum_Len {

	Scanner sc = new Scanner(System.in);
	public int size, s;
	int arr[]=new int[100];
	public
	void getdata(){
	System.out.println("Enter the size of the array: ");
	size = sc.nextInt();
	System.out.println("Enter the elements: ");
	for (int i = 0; i < size; i++) {
	arr[i] = sc.nextInt();
	if(arr[i]<0)
	{throw new InputMismatchException("invalid input please put value greater than 0");}
	else {
	continue;
	}
	}
	}
	int getsum() {
	if (size % 2 == 0) {
	s = arr[0] + arr[size-1];
	System.out.println("The no. of the elements is even.");
	}
	else{
	s = arr[0]+arr[size-1]+arr[(size-1)/2];
	System.out.println("The no. of the elements is odd.");
}
	return s;
	}
	public static void main(String []args){
	Arr_Sum_Len obj = new Arr_Sum_Len();
	obj.getdata();
	int sum = obj.getsum();
	System.out.println("The sum of the required elements: " + sum);
	}
	}