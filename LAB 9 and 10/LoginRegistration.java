import java.awt.*;
import java.util.ArrayList;
import javax.swing.*;

class User {
    private String username;
    private String password;
    private String email;

    public User(String username, String password, String email) {
        this.username = username;
        this.password = password;
        this.email = email;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getEmail() {
        return email;
    }
}

public class LoginRegistration extends JFrame {
    private ArrayList<User> users;
    private JTextField usernameField, emailField;
    private JPasswordField passwordField;

    public LoginRegistration() {
        setTitle("Login & Registration");
        setSize(400, 300);
        setLayout(new CardLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        users = new ArrayList<>();

        // Preload example users
        users.add(new User("A", "123", "a@example.com"));
        users.add(new User("B", "123", "b@example.com"));
        users.add(new User("C", "123", "c@example.com"));

        JPanel registrationPanel = createRegistrationPanel();
        JPanel loginPanel = createLoginPanel();

        add(registrationPanel, "Register");
        add(loginPanel, "Login");

        setVisible(true);
    }

    private JPanel createRegistrationPanel() {
        JPanel panel = new JPanel(new GridLayout(5, 1));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        usernameField = new JTextField();
        emailField = new JTextField();
        passwordField = new JPasswordField();
        JButton registerButton = new JButton("Register");
        JButton switchToLoginButton = new JButton("Go to Login");

        panel.add(new JLabel("Username:"));
        panel.add(usernameField);
        panel.add(new JLabel("Email:"));
        panel.add(emailField);
        panel.add(new JLabel("Password:"));
        panel.add(passwordField);
        panel.add(registerButton);
        panel.add(switchToLoginButton);

        registerButton.addActionListener(e -> {
            String username = usernameField.getText();
            String email = emailField.getText();
            String password = new String(passwordField.getPassword());

            if (username.isEmpty() || email.isEmpty() || password.isEmpty()) {
                JOptionPane.showMessageDialog(this, "All fields are required!");
            } else if (users.stream().anyMatch(user -> user.getUsername().equals(username))) {
                JOptionPane.showMessageDialog(this, "Username already exists!");
            } else {
                users.add(new User(username, password, email));
                JOptionPane.showMessageDialog(this, "Registration successful!");
                usernameField.setText("");
                emailField.setText("");
                passwordField.setText("");
            }
        });

        switchToLoginButton.addActionListener(e -> switchPanel("Login"));

        return panel;
    }

    private JPanel createLoginPanel() {
        JPanel panel = new JPanel(new GridLayout(4, 1));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        JTextField loginUsernameField = new JTextField();
        JPasswordField loginPasswordField = new JPasswordField();
        JButton loginButton = new JButton("Login");
        JButton switchToRegisterButton = new JButton("Go to Register");

        panel.add(new JLabel("Username:"));
        panel.add(loginUsernameField);
        panel.add(new JLabel("Password:"));
        panel.add(loginPasswordField);
        panel.add(loginButton);
        panel.add(switchToRegisterButton);

        loginButton.addActionListener(e -> {
            String username = loginUsernameField.getText();
            String password = new String(loginPasswordField.getPassword());

            boolean found = users.stream()
                .anyMatch(user -> user.getUsername().equals(username) && user.getPassword().equals(password));

            if (found) {
                JOptionPane.showMessageDialog(this, "Login successful!");
            } else {
                JOptionPane.showMessageDialog(this, "Invalid credentials!");
            }
        });

        switchToRegisterButton.addActionListener(e -> switchPanel("Register"));

        return panel;
    }

    private void switchPanel(String panelName) {
        CardLayout cl = (CardLayout) getContentPane().getLayout();
        cl.show(getContentPane(), panelName);
    }

    public static void main(String[] args) {
        new LoginRegistration();
    }
}

// (A, 123, a@example.com
// (B, 123, b@example.com
// (C, 123, c@example.com