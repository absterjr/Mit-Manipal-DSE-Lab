import java.util.Scanner; 
public class Bonus {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scin = new Scanner(System.in);
		int brick1[] = new int[3];
		int brick2[] = new int[3];
		int vol1 = 1;
		int vol2 = 1;
		System.out.println("Enter Brick1 details");
		for(int i=0;i<3;i++) {
		
		brick1[i] = scin.nextInt();
		vol1 = vol1*brick1[i];
		}
		System.out.println("Enter Brick2 details");
		// System.out.println(vol1);
		for(int i=0;i<3;i++) {
		
		brick2[i] = scin.nextInt();
		vol2 = vol2*brick2[i];
		}
		// System.out.println(vol2);
		int dif = Math.abs(vol1 - vol2);
		System.out.println("Difference : " + dif);

	}

}
