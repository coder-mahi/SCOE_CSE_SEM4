//Name = Labhade Siddharth Popat
//Roll No. : 155

// Source Code

import java.util.Scanner;

class LP {
    private int currentSize, maxSize;
    private String[] key;
    private String[] value;

    LP(int size) {
        currentSize = 0;
        maxSize = size;
        key = new String[maxSize];
        value = new String[maxSize];
    }

    private int hash(String k) {
       // return Math.abs(k.hashCode()) % maxSize;
       return Integer.parseInt(k)%maxSize;
    }

    public void insert(String k, String v) {
        if (currentSize >= maxSize) {
            System.out.println("Hash Table is full.");
            return;
        }
        
        int temp = hash(k);
        int i = temp;

        do {
            if (key[i] == null) {
                key[i] = k;
                value[i] = v;
                currentSize++;
                return;
            }
            if (key[i].equals(k)) {
                value[i] = v; 
                return;
            }
            i = (i + 1) % maxSize;
        } while (i != temp);
    }

    public void remove(String k) {
        int index = hash(k);
        int i = index;


        do {
            if (key[i] == null) {
                System.out.println("Key not found.");
                return;
            }
            if (key[i].equals(k)) {
                key[i] = null;
                value[i] = null;
                currentSize--;
                System.out.println("Key removed.");
                return;
            }
            i = (i + 1) % maxSize;
        } while (i != index);
        
        System.out.println("Key not found.");
    }

    public String get(String k) {
        int index = hash(k);
        int i = index;

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
    public void makeEmpty()
    {
        currentSize=0;
        key=new String[maxSize];
        value=new String[maxSize];
    }

    public int size() {
        return currentSize;
    }

    public void display() {
        for (int i = 0; i < maxSize; i++) {
            if (key[i] != null) {
                System.out.println(i+" "+"Key: " + key[i] + ", Value: " + value[i]);
            }
        }
    }
}

public class HashTableEX {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the table:");
        int a = sc.nextInt();
        LP l = new LP(a);

        while (true) {
            System.out.println("*** Menu ***\n1. Insert\n2. Remove\n3. Get\n4. Display\n5. Size\n6. Clear\n7. Exit\n Enter the choice of operation:");
            int ch = sc.nextInt();
            
            switch (ch) {
                case 1:
                    System.out.println("Enter the Key and Value:");
                    l.insert(sc.next(), sc.next());
                    break;
                case 2:
                    System.out.println("Enter the key to Remove:");
                    l.remove(sc.next());
                    break;
                case 3:
                    System.out.println("Enter the key to Get:");
                    String value = l.get(sc.next());
                    if (value != null) {
                        System.out.println("Value: " + value);
                    } else {
                        System.out.println("Key not found.");
                    }
                    break;
                case 4:
                    l.display();
                    break;
                case 5:
                    System.out.println("Current Size: " + l.size());
                    break;
                case 6:
                    System.out.println("Table is Clear");
                    l.makeEmpty();
                    break;
                case 7:
                    System.out.println("Exiting.");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

/*Output
Enter the size of the table:
5
*** Menu ***
1. Insert
2. Remove
3. Get
4. Display
5. Size
6. Clear
7. Exit
 Enter the choice of operation:
1
Enter the Key and Value:
13 sidd
*** Menu ***
1. Insert
2. Remove
3. Get
4. Display
5. Size
6. Clear
7. Exit
 Enter the choice of operation:
2
Enter the key to Remove:
11
Key not found.
*** Menu ***
1. Insert
2. Remove
3. Get
4. Display
5. Size
6. Clear
7. Exit
 Enter the choice of operation:
4
3 Key: 13, Value: sidd
*** Menu ***
1. Insert
2. Remove
3. Get
4. Display
5. Size
6. Clear
7. Exit
 Enter the choice of operation:
3
Enter the key to Get:
13
Value: sidd
*** Menu ***
1. Insert
2. Remove
3. Get
4. Display
5. Size
6. Clear
7. Exit
 Enter the choice of operation:

 */
