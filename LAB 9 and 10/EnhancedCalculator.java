import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EnhancedCalculator extends JFrame {
    private JTextField input1, input2, result;
    private JComboBox<String> operation;

    public EnhancedCalculator() {
        setTitle("Enhanced Calculator");
        setSize(400, 300);
        setLayout(new GridLayout(5, 2, 10, 10));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        input1 = new JTextField();
        input2 = new JTextField();
        result = new JTextField();
        result.setEditable(false);

        operation = new JComboBox<>(new String[]{"+", "-", "*", "/"});

        JButton calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(e -> calculate());

        add(new JLabel("Number 1:"));
        add(input1);
        add(new JLabel("Operation:"));
        add(operation);
        add(new JLabel("Number 2:"));
        add(input2);
        add(new JLabel("Result:"));
        add(result);
        add(calculateButton);

        setVisible(true);
    }

    private void calculate() {
        try {
            double num1 = Double.parseDouble(input1.getText());
            double num2 = Double.parseDouble(input2.getText());
            String op = (String) operation.getSelectedItem();
            double res;

            switch (op) {
                case "+" -> res = num1 + num2;
                case "-" -> res = num1 - num2;
                case "*" -> res = num1 * num2;
                case "/" -> res = num1 / num2;
                default -> throw new IllegalStateException("Unexpected value: " + op);
            }

            result.setText(String.valueOf(res));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter valid numbers.");
        }
    }

    public static void main(String[] args) {
        new EnhancedCalculator();
    }
}
