import java.util.Scanner;
import main.p3.DB;
public class Assignment4 extends DB{
    public void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name: ");
        setStudName(sc.nextLine());
        System.out.print("Enter roll number: ");
        setStudRoll(sc.nextInt());
        sc.nextLine(); 
        System.out.print("Enter faculty name: ");
        setFacultyName(sc.nextLine());
        System.out.print("Enter faculty ID: ");
        setFacultyID(sc.nextInt());
        sc.nextLine();
        System.out.print("Enter college code: ");
        setCode(sc.nextInt());
        sc.nextLine(); 
        System.out.print("Enter college name: ");
        setClgName(sc.nextLine());
        System.out.print("Enter number of placed students: ");
        setPlacementRecords(sc.nextInt());
    }
    
    public void display() {
        System.out.println("Student Name: "+getStudName());
        System.out.println("Roll Number: "+getRollNo());
        System.out.println("Faculty Name: "+getFacultyName());
        System.out.println("Faculty ID: "+getFacultyID());
        System.out.println("College Code: "+getCode());
        System.out.println("College Name: "+getClgName());
        System.out.println("Placed Students: "+getPlacementRecord());
    }
    public static void main(String[] args){
        int ch,c;
        Scanner sc=new Scanner(System.in);
        Assignment4 obj = new Assignment4();
        do{
            System.out.println("Choose Operation...");
            System.out.println("1.Accept details");
            System.out.println("2.Display details");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    obj.accept();
                    break;
                case 2:
                    obj.display();
                    break;
                
                default:
                    System.out.println("invalid option...");
            }
            System.out.println("do you want to contiiinue?");
            c = sc.nextInt();
        } while (c == 1);
    }
}