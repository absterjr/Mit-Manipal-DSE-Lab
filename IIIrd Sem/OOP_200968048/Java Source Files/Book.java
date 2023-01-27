import java.util.Scanner;
public class Book {
Scanner sc = new Scanner(System.in);
public
String Name;
String Author;
int id, price;
public
Book(){
	Name = "XXXX";
	Author = "xxxx";
	id = 0000;
	price = 00;
}
Book(String name, String Author, int ID, int price){
	this.Name = name;
	this.Author = Author;
	this.id = ID;
	this.price = price;
}
void getName(){
	System.out.println("Enter the Name of the book: ");
	Name = sc.nextLine();
}
void getAuthor() {
	System.out.println("Enter the author of the book: ");
	Author = sc.nextLine();
}
void getID(){
	System.out.println("Enter the ID of the book: ");
	id = sc.nextInt();
}
void getPrice(){
	System.out.println("Enter the Price of the book: ");
	price = sc.nextInt();
}
void display(){
	System.out.println("The Name of the book is: "+Name);
	System.out.println("The Author of the book is: " + Author.toUpperCase());
	System.out.println("The ID of the book is: "+id);
	System.out.println("The Price of the book is: "+price);
}
public static void main(String []args){
	Book ob = new Book(" "," ",00000,0000);
	ob.getName();
	ob.getID();
	ob.getPrice();
	ob.display();

}
}