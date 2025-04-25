import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class BankManagementSystem extends JFrame {
    private JTable customerTable;
    private DefaultTableModel tableModel;
    private JButton addButton, editButton, deleteButton, refreshButton, avgButton;
    private Connection connection;

    public BankManagementSystem() {
        setTitle("Bank Management System");
        setSize(800, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        connectToDatabase();

        String[] columnNames = {"ID", "Name", "Email", "Phone", "Balance"};
        tableModel = new DefaultTableModel(columnNames, 0);
        customerTable = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(customerTable);

        addButton = new JButton("Add Customer");
        editButton = new JButton("Edit Customer");
        deleteButton = new JButton("Delete Customer");
        refreshButton = new JButton("Refresh");
        avgButton = new JButton("Show Average Balance");

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(addButton);
        buttonPanel.add(editButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(refreshButton);
        buttonPanel.add(avgButton);

        setLayout(new BorderLayout());
        add(scrollPane, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);

        addButton.addActionListener(e -> showCustomerDialog(null));
        editButton.addActionListener(e -> {
            int selectedRow = customerTable.getSelectedRow();
            if (selectedRow >= 0) {
                int customerId = (int) customerTable.getValueAt(selectedRow, 0);
                showCustomerDialog(customerId);
            } else {
                JOptionPane.showMessageDialog(this, "Please select a customer.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        deleteButton.addActionListener(e -> {
            int selectedRow = customerTable.getSelectedRow();
            if (selectedRow >= 0) {
                int customerId = (int) customerTable.getValueAt(selectedRow, 0);
                deleteCustomer(customerId);
            } else {
                JOptionPane.showMessageDialog(this, "Please select a customer.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        refreshButton.addActionListener(e -> refreshCustomerTable());
        avgButton.addActionListener(e -> showAverageBalance());

        refreshCustomerTable();
    }

    private void showAverageBalance() {
        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT AVG(balance) AS average_balance FROM customers")) {
            
            if (rs.next()) {
                double average = rs.getDouble("average_balance");
                JOptionPane.showMessageDialog(this, 
                    String.format("Average Balance: $%.2f", average), 
                    "Average Balance", 
                    JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, 
                "Error calculating average balance: " + e.getMessage(), 
                "Error", 
                JOptionPane.ERROR_MESSAGE);
        }
    }

    private void connectToDatabase() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/bms",
                "root", 
                "mahesh" 
            );
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Database connection failed: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
    }

    private void refreshCustomerTable() {
        tableModel.setRowCount(0); 
        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT * FROM customers")) {
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("customer_id"),
                    rs.getString("name"),
                    rs.getString("email"),
                    rs.getString("phone"),
                    rs.getDouble("balance")
                };
                tableModel.addRow(row);
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Error loading customers: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void showCustomerDialog(Integer customerId) {
        JDialog dialog = new JDialog(this, customerId == null ? "Add Customer" : "Edit Customer", true);
        dialog.setSize(400, 300);
        dialog.setLayout(new GridLayout(5, 2, 10, 10));

        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField();
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField();
        JLabel phoneLabel = new JLabel("Phone:");
        JTextField phoneField = new JTextField();
        JLabel balanceLabel = new JLabel("Balance:");
        JTextField balanceField = new JTextField();

        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");

        if (customerId != null) {
            try (PreparedStatement stmt = connection.prepareStatement("SELECT * FROM customers WHERE customer_id = ?")) {
                stmt.setInt(1, customerId);
                ResultSet rs = stmt.executeQuery();
                if (rs.next()) {
                    nameField.setText(rs.getString("name"));
                    emailField.setText(rs.getString("email"));
                    phoneField.setText(rs.getString("phone"));
                    balanceField.setText(String.valueOf(rs.getDouble("balance")));
                }
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(dialog, "Error loading customer: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }

        dialog.add(nameLabel);
        dialog.add(nameField);
        dialog.add(emailLabel);
        dialog.add(emailField);
        dialog.add(phoneLabel);
        dialog.add(phoneField);
        dialog.add(balanceLabel);
        dialog.add(balanceField);
        dialog.add(saveButton);
        dialog.add(cancelButton);

        saveButton.addActionListener(e -> {
            try {
                String name = nameField.getText();
                String email = emailField.getText();
                String phone = phoneField.getText();
                double balance = Double.parseDouble(balanceField.getText());

                if (customerId == null) {
                    try (PreparedStatement stmt = connection.prepareStatement(
                            "INSERT INTO customers (name, email, phone, balance) VALUES (?, ?, ?, ?)")) {
                        stmt.setString(1, name);
                        stmt.setString(2, email);
                        stmt.setString(3, phone);
                        stmt.setDouble(4, balance);
                        stmt.executeUpdate();
                        JOptionPane.showMessageDialog(dialog, "Customer added successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
                    }
                } else {
                    try (PreparedStatement stmt = connection.prepareStatement(
                            "UPDATE customers SET name=?, email=?, phone=?, balance=? WHERE customer_id=?")) {
                        stmt.setString(1, name);
                        stmt.setString(2, email);
                        stmt.setString(3, phone);
                        stmt.setDouble(4, balance);
                        stmt.setInt(5, customerId);
                        stmt.executeUpdate();
                        JOptionPane.showMessageDialog(dialog, "Customer updated successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
                    }
                }
                refreshCustomerTable();
                dialog.dispose();
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(dialog, "Invalid balance value!", "Error", JOptionPane.ERROR_MESSAGE);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(dialog, "Database error: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        cancelButton.addActionListener(e -> dialog.dispose());
        dialog.setVisible(true);
    }

    private void deleteCustomer(int customerId) {
        int confirm = JOptionPane.showConfirmDialog(
            this,
            "Are you sure you want to delete this customer?",
            "Confirm Delete",
            JOptionPane.YES_NO_OPTION
        );
        if (confirm == JOptionPane.YES_OPTION) {
            try (PreparedStatement stmt = connection.prepareStatement(
                    "DELETE FROM customers WHERE customer_id = ?")) {
                stmt.setInt(1, customerId);
                stmt.executeUpdate();
                refreshCustomerTable();
                JOptionPane.showMessageDialog(this, "Customer deleted successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(this, "Error deleting customer: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
                new BankManagementSystem().setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
}