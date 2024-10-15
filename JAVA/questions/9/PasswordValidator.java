//Question 9

import java.util.Scanner;

public class PasswordValidator {

    public static boolean isValidPassword(String password) {
        if (password.length() < 5 || password.length() > 12) {
            return false;
        }
        
        boolean hasLowercase = false;
        boolean hasDigit = false;
        
        for (int i = 0; i < password.length(); i++) {
            char ch = password.charAt(i);
            
            if (Character.isLowerCase(ch)) {
                hasLowercase = true;
            } else if (Character.isDigit(ch)) {
                hasDigit = true;
            } else if (Character.isUpperCase(ch) || !Character.isLetterOrDigit(ch)) {
                return false; // contains uppercase or special character
            }
            
            if (i > 0 && password.charAt(i) == password.charAt(i - 1)) {
                return false; // contains immediate repeating characters
            }
        }
        
        return hasLowercase && hasDigit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        
        if (isValidPassword(password)) {
            System.out.println("Password is valid");
        } else {
            System.out.println("Password is invalid");
        }
        
        scanner.close();
    }
}
