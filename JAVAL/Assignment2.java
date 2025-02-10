import java.util.Scanner;

abstract class Vehicle {
    String brand;
    String model;

    public Vehicle(String brand, String model) {
        this.brand = brand;
        this.model = model;
        System.out.println("Vehicle created: Brand - " + brand + ", Model - " + model);
    }
    public abstract void start();
    public abstract void stop();
    public final void vehicleInfo() {
        System.out.println("Vehicle of: Brand - " + this.brand + ", Model - " + this.model);
    }
}
class Car extends Vehicle {
    public Car(String brand, String model) {
        super(brand, model);
    }
    @Override
    public void start() {
        System.out.println(this.brand + " Car started.");
    }
    @Override
    public void stop() {
        System.out.println("Car stopped.");
    }
    public void showCarDetails() {
        System.out.println("Car Details: Brand - " + this.brand + ", Model - " + this.model);
    }
}
class Bike extends Vehicle {
    public Bike(String brand, String model) {
        super(brand, model);
    }
    @Override
    public void start() {
        System.out.println(this.brand + " Bike started.");
    }
    @Override
    public void stop() {
        System.out.println("Bike stopped.");
    }
    public void showBikeDetails() {
        System.out.println("Bike Details: Brand - " + this.brand + ", Model - " + this.model);
    }
}
class Truck extends Vehicle {
    public Truck(String brand, String model) {
        super(brand, model);
    }
    @Override
    public void start() {
        System.out.println(this.brand + " Truck started.");
    }
    @Override
    public void stop() {
        System.out.println("Truck stopped.");
    }
    public void showTruckDetails() {
        System.out.println("Truck Details: Brand - " + this.brand + ", Model - " + this.model);
    }
}
public class Assignment2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nSelect Vehicle Type:\n1. Car\n2. Bike\n3. Truck\n4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();  
            switch (choice) {
                case 1:
                    System.out.print("Enter Car Brand: ");
                    String carBrand = scanner.next();
                    scanner.nextLine(); 
                    System.out.print("Enter Car Model: ");
                    String carModel = scanner.next();
                    scanner.nextLine(); 
                    Car car = new Car(carBrand, carModel);
                    car.start();
                    car.stop();
                    car.vehicleInfo();
                    car.showCarDetails();
                    break;

                case 2:
                    System.out.print("Enter Bike Brand: ");
                    String bikeBrand = scanner.next();
                    scanner.nextLine(); 
                    System.out.print("Enter Bike Model: ");
                    String bikeModel = scanner.next();
                    scanner.nextLine(); 
                    Bike bike = new Bike(bikeBrand, bikeModel);
                    bike.start();
                    bike.stop();
                    bike.vehicleInfo();
                    bike.showBikeDetails();
                    break;

                case 3:
                    System.out.print("Enter Truck Brand: ");
                    String truckBrand = scanner.next();
                    scanner.nextLine(); 
                    System.out.print("Enter Truck Model: ");
                    String truckModel = scanner.next();
                    scanner.nextLine(); 
                    Truck truck = new Truck(truckBrand, truckModel);
                    truck.start();
                    truck.stop();
                    truck.vehicleInfo();
                    truck.showTruckDetails();
                    break;
                case 4:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 4);

        scanner.close();
    }
}
