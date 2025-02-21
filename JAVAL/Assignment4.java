import com.packagexyz.DB;
import java.util.*;
public class Assignment4 extends DB{
    void accept(){
        System.out.println("Enter college details..");


    }
    void display(){

    }
    public static void main(String[] args) {
        int ch,c;
        Scanner sc = new Scanner(System.in);
        Assignment4 obj = new Assignment4();
        do{ 
            System.out.println("Choose Operation...");
            System.out.println("1. Accept college details");
            System.out.println("2. Display College details");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                    obj.accept();
                    break;
                case 2:
                    obj.display();
                    break;
                default:
                    System.out.println("choosen invalid option...");
            }
            System.out.println("DO you want to contiue?? (1/0)");
            c = sc.nextInt();
        }while(c==1);
    }
}
