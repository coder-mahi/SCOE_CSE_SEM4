import java.util.*;
import main.p3.*;
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
        System.out.print("Enter faculty Id:");
        setFacultyID(sc.nextInt());
        sc.nextLine();

        System.out.print("Enter clg code :");
        setCode(sc.nextInt());
        sc.nextLine(); 
        System.out.print("Enter clg name: ");
        setClgName(sc.nextLine());
       
        System.out.print("Is "+getStudName()+" student placed ?");
        setPlacedOrNot(sc.nextBoolean());

        System.out.print("Enter number of placed students: ");
        setPlacementRecords(sc.nextInt());

        sc.close();
    }
    
    public void display() {
        System.out.println("Student name:"+getStudName());
        System.out.println("Roll number: "+getRollNo());

        System.out.println("Faculty Name:"+getFacultyName());

        System.out.println("Faculty id "+getFacultyID());
        
        System.out.println("College code:"+getCode());
        System.out.println("College name:"+getClgName());

        System.out.println("Is "+getStudName()+" is placed : "+getPlacedOrNot());

        System.out.println("Placed Students : "+getPlacementRecord());
    }

    public static void main(String[] args){
        int ch;
        int c;

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
                    System.out.println("invalid optionn...");
            }
            System.out.println("do you want to contiiinue........");
            c=sc.nextInt();
        } while(c==1);

        sc.close();
        }
}