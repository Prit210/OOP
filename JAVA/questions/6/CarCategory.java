//Question 6

import java.util.Scanner;

public class CarCategory {
    public static String getCarModel(String category) {
        switch (category.toUpperCase()) {
            case "SUV":
                return "TATA SAFARI";
            case "SEDAN":
                return "TATA INDIGO";
            case "ECONOMY":
                return "TATA INDICA";
            case "MINI":
                return "TATA NANO";
            default:
                return "Unknown Category";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter car category (SUV, SEDAN, ECONOMY, MINI): ");
        String category = scanner.nextLine();

        System.out.println("Car Model: " + getCarModel(category));
        scanner.close();
    }
}
