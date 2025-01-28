import java.util.ArrayList;
import java.util.Scanner;
class Voter {
    private int voterID;
    private String name;
    private int age;
    public Voter(int voterID, String name, int age) {
        this.voterID = voterID;
        this.name = name;
        this.age = age;
    }
    public boolean isEligible() {
        return age >= 18;
    }
    public void displayDetails() {
        System.out.println("Voter ID: " + voterID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Eligibility: " + (isEligible() ? "Eligible" : "Not Eligible"));
    }
}

public class VoterDB {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Voter> voterList = new ArrayList<>();
        int choice;
        do {
            System.out.println("\nVoter Database Menu:");
            System.out.println("1. Add Voter");
            System.out.println("2. Display Voter Details");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1: 
                    System.out.print("Enter Voter ID: ");
                    int voterID = scanner.nextInt();
                    scanner.nextLine(); 
                    System.out.print("Enter Name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter Age: ");
                    int age = scanner.nextInt();

                    Voter voter = new Voter(voterID, name, age);
                    voterList.add(voter);
                    System.out.println("Voter added successfully!");
                    break;

                case 2: 
                    if (voterList.isEmpty()) {
                        System.out.println("No voters in the database.");
                    } else {
                        for (Voter v : voterList) {
                            v.displayDetails();
                            System.out.println("-------------------");
                        }
                    }
                    break;

                case 3: 
                    System.out.println("Exiting Voter Database. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 3);
        scanner.close();
    }
}
