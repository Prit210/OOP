import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class StudentManagement extends JFrame {
    private JTextField idField, nameField, ageField, genderField, deptField;
    private JTable table;
    private DefaultTableModel model;

    public StudentManagement() {
        setTitle("Student Management System");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Center the frame
        setLocationRelativeTo(null);

        // Create Header Panel
        JLabel headerLabel = new JLabel("Student Management System", SwingConstants.CENTER);
        headerLabel.setFont(new Font("Arial", Font.BOLD, 18));
        headerLabel.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        add(headerLabel, BorderLayout.NORTH);

        // Form Panel
        JPanel formPanel = new JPanel(new GridLayout(5, 2, 10, 10));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));
        idField = createInputField("Student ID:", formPanel);
        nameField = createInputField("Name:", formPanel);
        ageField = createInputField("Age:", formPanel);
        genderField = createInputField("Gender:", formPanel);
        deptField = createInputField("Department:", formPanel);
        add(formPanel, BorderLayout.WEST);

        // Button Panel
        JPanel buttonPanel = new JPanel(new GridLayout(1, 4, 10, 0));
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));
        buttonPanel.add(createButton("Add", new AddAction()));
        buttonPanel.add(createButton("Update", new UpdateAction()));
        buttonPanel.add(createButton("Delete", new DeleteAction()));
        buttonPanel.add(createButton("View", new ViewAction()));
        add(buttonPanel, BorderLayout.SOUTH);

        // Table Panel
        model = new DefaultTableModel(new String[]{"ID", "Name", "Age", "Gender", "Department"}, 0);
        table = new JTable(model);
        JScrollPane tablePane = new JScrollPane(table);
        tablePane.setBorder(BorderFactory.createTitledBorder("Student Records"));
        add(tablePane, BorderLayout.CENTER);

        setVisible(true);
    }

    private JTextField createInputField(String label, JPanel panel) {
        panel.add(new JLabel(label));
        JTextField textField = new JTextField();
        panel.add(textField);
        return textField;
    }

    private JButton createButton(String text, ActionListener listener) {
        JButton button = new JButton(text);
        button.addActionListener(listener);
        button.setToolTipText("Click to " + text.toLowerCase() + " student record.");
        return button;
    }

    // Action Classes
    private class AddAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "#Prit@MYSQL#");
                 PreparedStatement ps = conn.prepareStatement("INSERT INTO students VALUES (?, ?, ?, ?, ?)")) {
                ps.setString(1, idField.getText());
                ps.setString(2, nameField.getText());
                ps.setInt(3, Integer.parseInt(ageField.getText()));
                ps.setString(4, genderField.getText());
                ps.setString(5, deptField.getText());
                ps.executeUpdate();
                JOptionPane.showMessageDialog(null, "Student Added!");
                clearFields();
            } catch (SQLException ex) {
                showError(ex.getMessage());
            }
        }
    }

    private class UpdateAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "");
                 PreparedStatement ps = conn.prepareStatement("UPDATE students SET name = ?, age = ?, gender = ?, department = ? WHERE id = ?")) {
                ps.setString(1, nameField.getText());
                ps.setInt(2, Integer.parseInt(ageField.getText()));
                ps.setString(3, genderField.getText());
                ps.setString(4, deptField.getText());
                ps.setString(5, idField.getText());
                ps.executeUpdate();
                JOptionPane.showMessageDialog(null, "Student Updated!");
                clearFields();
            } catch (SQLException ex) {
                showError(ex.getMessage());
            }
        }
    }

    private class DeleteAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int confirm = JOptionPane.showConfirmDialog(null, "Are you sure you want to delete this student?", "Delete Confirmation", JOptionPane.YES_NO_OPTION);
            if (confirm == JOptionPane.YES_OPTION) {
                try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "");
                     PreparedStatement ps = conn.prepareStatement("DELETE FROM students WHERE id = ?")) {
                    ps.setString(1, idField.getText());
                    ps.executeUpdate();
                    JOptionPane.showMessageDialog(null, "Student Deleted!");
                    clearFields();
                } catch (SQLException ex) {
                    showError(ex.getMessage());
                }
            }
        }
    }

    private class ViewAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "");
                 Statement stmt = conn.createStatement();
                 ResultSet rs = stmt.executeQuery("SELECT * FROM students")) {
                model.setRowCount(0);
                while (rs.next()) {
                    model.addRow(new Object[]{rs.getString("id"), rs.getString("name"), rs.getInt("age"), rs.getString("gender"), rs.getString("department")});
                }
            } catch (SQLException ex) {
                showError(ex.getMessage());
            }
        }
    }

    private void clearFields() {
        idField.setText("");
        nameField.setText("");
        ageField.setText("");
        genderField.setText("");
        deptField.setText("");
    }

    private void showError(String message) {
        JOptionPane.showMessageDialog(this, "Error: " + message, "Error", JOptionPane.ERROR_MESSAGE);
    }

    public static void main(String[] args) {
        new StudentManagement();
    }
}
