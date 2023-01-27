import java.util.Scanner;
public class Sum_Arr {

Scanner sc = new Scanner(System.in);
public int size;
float arr[] = new float[100];
public float s=0;
void getele() {
System.out.println("Enter the size of the array: ");
size = sc.nextInt();
System.out.println("Enter the elements: ");
for (int i = 0; i < size; i++) {
arr[i] = sc.nextFloat();
}
}

float getsum() {
for (int i = 0; i < size; i++) {
s = s + arr[i];
}
return s;

}

public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
Sum_Arr obj = new Sum_Arr();
obj.getele();
float sum = obj.getsum();
System.out.println("The sum of the elements of the array: " + sum);
}}
