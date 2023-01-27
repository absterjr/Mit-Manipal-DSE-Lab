import java.util.InputMismatchException;
import java.util.Scanner;
public class StudentInfo {
	Scanner sc = new Scanner(System.in);
	public
	int id, total, avg, fail=0;
	int []marks = new int[4];
	private Object ascii;
	public
	StudentInfo(){
	id = 0000;
	marks[0]=90;
	marks[1]=80;
	marks[2]=85;
	marks[3]=88;
	}
	void getid(){
	System.out.println("Enter ID: ");
	id = sc.nextInt();
	}
	void getmarks(){
		try {
	System.out.println("Enter Marks: ");
	for(int i=0; i<4;i++){
	System.out.print("Subject " + i + ":");
	marks[i] = sc.nextInt();
	if(marks[i]<0)
	{throw new InputMismatchException("Invalid Input");}
	else {
	continue;
	}
	}
	}
		
		catch(Exception e) {
			System.out.println("Enter Valid Marks");
		}
	}
	void calc(){
	for(int i=0; i<4; i++){
	if(marks[i]<=40){
	fail+=1;
	total+=marks[i];
	avg=total/4;
	}
	else{
	total+=marks[i];
	avg=total/4;
	}
	}

	}
	String asciiString = Arrays.toString(ascii);
	System.out.println(asciiString);
	void display(){
		System.out.println("ID : "+id);
		System.out.println("Grand Total: " + total);
		System.out.println("Percentage: "+avg);
	if(fail>0){
	System.out.println("Candidate has failed in one or more subjects! ");	
	}
	else{
	System.out.println("Candidate has passed in all subjects! Congratulations! ");
	}
	}
	public static void main(String []args){
	StudentInfo ob = new StudentInfo();
	ob.getid();
	ob.getmarks();
	ob.calc();
	ob.display();
	}
	}