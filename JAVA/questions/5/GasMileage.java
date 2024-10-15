//Question 5

import java.util.Scanner;

public class GasMileage {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int miles, gallons;
        double totalMiles = 0, totalGallons = 0;

        while (true) {
            System.out.print("Enter miles driven (-1 to end): ");
            miles = scanner.nextInt();
            if (miles == -1) {
                break;
            }

            System.out.print("Enter gallons used: ");
            gallons = scanner.nextInt();

            totalMiles += miles;
            totalGallons += gallons;

            double mpg = (double) miles / gallons;
            System.out.printf("Miles per gallon for this trip: %.2f%n", mpg);

            double totalMpg = totalMiles / totalGallons;
            System.out.printf("Combined miles per gallon: %.2f%n", totalMpg);
        }

        scanner.close();
    }
}
