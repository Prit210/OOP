//Question 3

class Employee {
    private String firstName;
    private String lastName;
    private double monthlySalary;

    public Employee(String firstName, String lastName, double monthlySalary) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.monthlySalary = Math.max(monthlySalary, 0.0);
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getMonthlySalary() {
        return monthlySalary;
    }

    public void setMonthlySalary(double monthlySalary) {
        this.monthlySalary = Math.max(monthlySalary, 0.0);
    }

    public double getYearlySalary() {
        return monthlySalary * 12;
    }

    public void giveRaise(double percentage) {
        monthlySalary += monthlySalary * percentage / 100;
    }
}

public class EmployeeTest {
    public static void main(String[] args) {
        Employee emp1 = new Employee("John", "Doe", 3000);
        Employee emp2 = new Employee("Jane", "Doe", 4000);
        
        System.out.println("Yearly Salary of " + emp1.getFirstName() + ": " + emp1.getYearlySalary());
        System.out.println("Yearly Salary of " + emp2.getFirstName() + ": " + emp2.getYearlySalary());
        
        emp1.giveRaise(10);
        emp2.giveRaise(10);
        
        System.out.println("After raise:");
        System.out.println("Yearly Salary of " + emp1.getFirstName() + ": " + emp1.getYearlySalary());
        System.out.println("Yearly Salary of " + emp2.getFirstName() + ": " + emp2.getYearlySalary());
    }
}
