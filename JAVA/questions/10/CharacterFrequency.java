//Question 10

import java.util.HashMap;
import java.util.Scanner;

public class CharacterFrequency {

    public static void printExceedingCharacters(String input, int threshold) {
        HashMap<Character, Integer> charCountMap = new HashMap<>();

        for (char ch : input.toCharArray()) {
            charCountMap.put(ch, charCountMap.getOrDefault(ch, 0) + 1);
        }

        System.out.println("Characters exceeding threshold " + threshold + ":");
        for (char ch : charCountMap.keySet()) {
            if (charCountMap.get(ch) > threshold) {
                System.out.println(ch + ": " + charCountMap.get(ch));
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        
        System.out.print("Enter the threshold: ");
        int threshold = scanner.nextInt();
        
        printExceedingCharacters(input, threshold);
        
        scanner.close();
    }
}
