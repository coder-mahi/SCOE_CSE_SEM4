import java.util.LinkedList;
import java.util.Scanner;
class Chain{
    private LinkedList<Integer>[] table;
    private int Size;
  
    Chain(int size) {
        this.Size=size;
        table=new LinkedList[Size];
        for(int i=0;i<Size;i++){
            table[i]=new LinkedList<>();
        }  
    }

    private int hash(int k) {
       return k % Size;
    }

    public void Insert(int k) {
        int index=hash(k);
        table[index].add(k);
        System.out.println(k+" is added succesfully");
    }

    public void Display(){
        for (int i = 0; i < Size; i++) {
            System.out.print("Index " + i + ": ");
            for (int key : table[i]) {
                System.out.print(key + " -> ");
            }
            System.out.println("null");
        }
    }
       
    

    public boolean Search_K(int searchkey){
            int index = searchkey % Size;
            return table[index].contains(searchkey);
        }
    
/* 
            do {
                if (key[i] == null) {
                    return null; // Key not found
                }
                if (key[i].equals(k)) {
                    return value[i]; // Return value if key found
                }
                i = (i + 1) % maxSize;
            } while (i != index);
            
            return null; // Key not found
        }
 */

    }

public class HashTableChaining{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the size of the table: ");
        int size=sc.nextInt();

        Chain cn=new Chain(size);

        while (true) {

        System.out.println("*** Menu ***\n1.Insert\n2.Display\n3.Search\n4.Exit");
        System.out.println("Enter your choice: ");
        int ch=sc.nextInt();
        switch (ch) {
            case 1:
                System.out.println("Enter the number of  key to insert :" );
                int key=sc.nextInt();
                System.out.println("Enter the key : ");
                for(int i=0;i<key;i++){
                    int k=sc.nextInt();
                    cn.Insert(k);
                }
                break;
            case 2:
                System.out.println("Hash table");
                cn.Display();
                break;
            case 3:
                System.out.print("Enter the key to search: ");
                int searchkey = sc.nextInt();
                if (cn.Search_K(searchkey)) {
                    System.out.println("Key found!");
                    } else {
                        System.out.println("Key not found!");
                    }
                break;
            case 4:
                System.out.println("Exiting...");
                sc.close();
                break;
            default:
                System.out.println("Invalid choice..Try Again");
        }
    }
    }
}