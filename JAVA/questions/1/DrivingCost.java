import java.util.Scanner;
//Question 1

public class DrivingCost {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter total miles driven per day: ");
            double milesPerDay = scanner.nextDouble();
            
            System.out.print("Enter cost per gallon of gasoline: ");
            double costPerGallon = scanner.nextDouble();
            
            System.out.print("Enter average fees per day: ");
            double feesPerDay = scanner.nextDouble();
            
            System.out.print("Enter tolls per day: ");
            double tollsPerDay = scanner.nextDouble();
            
            double dailyCost = (milesPerDay / 25.0) * costPerGallon + feesPerDay + tollsPerDay;
            System.out.printf("Your daily driving cost is: %.2f%n", dailyCost);
        }
    }
}
