import java.util.ArrayList;
import java.util.Scanner;

class Voter {
    String name;
    int dob;
    int age;
    String address;

    public Voter(String name, int dob, String address) {
        this.name = name;
        this.dob = dob;
        this.age = calculateAge(dob);
        this.address = address;
    }

    private int calculateAge(int dob) {
        int currentYear = 2025;
        return currentYear - dob;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("DOB: " + dob);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
        System.out.println("-------------------------");
    }
}

public class VoterDatabase {
    static ArrayList<Voter> voters = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    public static void addVoter() {
        System.out.print("Enter Name: ");
        String name = sc.next();
        System.out.print("Enter DOB (YYYY): ");
        int dob = sc.nextInt();
        System.out.print("Enter Address: ");
        sc.nextLine();
        String address = sc.nextLine();

        voters.add(new Voter(name, dob, address));
        System.out.println("Voter added successfully!\n");
    }

    public static void displayVoters() {
        if (voters.isEmpty()) {
            System.out.println("No voters found!\n");
            return;
        }
        System.out.println("\n--- Voter Details ---");
        for (Voter voter : voters) {
            voter.display();
        }
    }

    public static void modifyVoter() {
        System.out.print("Enter the voter's name to modify: ");
        String searchName = sc.next();
        boolean found = false;

        for (Voter voter : voters) {
            if (voter.name.equalsIgnoreCase(searchName)) {
                System.out.print("Enter new address: ");
                sc.nextLine();
                voter.address = sc.nextLine();
                System.out.println("Modification Successful!\n");
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Voter not found!\n");
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("--- Voter Database Management System ---");
            System.out.println("1. Add Voter");
            System.out.println("2. Display Voters");
            System.out.println("3. Modify Voter");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    addVoter();
                    break;
                case 2:
                    displayVoters();
                    break;
                case 3:
                    modifyVoter();
                    break;
                case 4:
                    System.out.println("Exiting the system.");
                    return;
                default:
                    System.out.println("Invalid choice, please try again!\n");
            }
        }
    }
}