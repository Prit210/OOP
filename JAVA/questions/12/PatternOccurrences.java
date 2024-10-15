//Question 12

import java.util.Scanner;

public class PatternOccurrences {

    public static int countPatternOccurrences(int a, int b, String pattern) {
        int count = 0;

        for (int i = a; i <= b; i++) {
            if (String.valueOf(i).contains(pattern)) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter start of the range: ");
        int a = scanner.nextInt();
        
        System.out.print("Enter end of the range: ");
        int b = scanner.nextInt();
        
        System.out.print("Enter pattern: ");
        String pattern = scanner.next();
        
        int occurrences = countPatternOccurrences(a, b, pattern);
        System.out.println("The pattern occurred " + occurrences + " times between " + a + " and " + b);
        
        scanner.close();
    }
}
