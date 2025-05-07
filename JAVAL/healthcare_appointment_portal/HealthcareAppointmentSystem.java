import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class HealthcareAppointmentSystem {
    public static void main(String[] args) {
        // Set look and feel to system default
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        // Create and show application on EDT
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new HealthcareAppointmentSystem();
            }
        });
    }
    // Database connection parameters
    private static final String DB_URL = "jdbc:mysql://localhost:3306/healthcare_db";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "mahesh";
    
    // GUI components
    private JFrame mainFrame;
    private JPanel mainPanel;
    private JTabbedPane tabbedPane;
    
    // Appointments tab components
    private JPanel appointmentsPanel;
    private JTable appointmentsTable;
    private DefaultTableModel appointmentsTableModel;
    private JButton addAppointmentBtn, deleteAppointmentBtn, updateAppointmentBtn;
    
    // Patients tab components
    private JPanel patientsPanel;
    private JTable patientsTable;
    private DefaultTableModel patientsTableModel;
    private JButton addPatientBtn, deletePatientBtn, updatePatientBtn;
    
    // Helper class for combo boxes
    private class ComboItem {
        private int id;
        private String name;
        
        public ComboItem(int id, String name) {
            this.id = id;
            this.name = name;
        }
        
        public int getId() {
            return id;
        }
        
        @Override
        public String toString() {
            return name;
        }
    }
    
    // Doctors tab components
    private JPanel doctorsPanel;
    private JTable doctorsTable;
    private DefaultTableModel doctorsTableModel;
    private JButton addDoctorBtn, deleteDoctorBtn, updateDoctorBtn;
    
    // Connection object
    private Connection connection;
    
    public HealthcareAppointmentSystem() {
        // Initialize database connection
        initializeDB();
        
        // Create and setup GUI
        createGUI();
        
        // Load initial data
        loadAppointments();
        loadPatients();
        loadDoctors();
    }
    
    private void initializeDB() {
        try {
            // Register MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            // Establish connection
            connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
            System.out.println("Database connection established successfully");
            
            // Create tables if they don't exist
            createTables();
            
        } catch (ClassNotFoundException e) {
            JOptionPane.showMessageDialog(null, "MySQL JDBC Driver not found: " + e.getMessage());
            System.exit(1);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null, "Database connection error: " + e.getMessage());
            System.exit(1);
        }
    }
    
    private void createTables() {
        try {
            Statement stmt = connection.createStatement();
            
            // Create Patients table
            String createPatientsTable = "CREATE TABLE IF NOT EXISTS patients (" +
                                         "patient_id INT AUTO_INCREMENT PRIMARY KEY, " +
                                         "name VARCHAR(100) NOT NULL, " +
                                         "gender VARCHAR(10), " +
                                         "dob DATE, " +
                                         "phone VARCHAR(15), " +
                                         "email VARCHAR(100), " +
                                         "address VARCHAR(255)" +
                                         ")";
            stmt.executeUpdate(createPatientsTable);
            
            // Create Doctors table
            String createDoctorsTable = "CREATE TABLE IF NOT EXISTS doctors (" +
                                        "doctor_id INT AUTO_INCREMENT PRIMARY KEY, " +
                                        "name VARCHAR(100) NOT NULL, " +
                                        "specialization VARCHAR(100), " +
                                        "phone VARCHAR(15), " +
                                        "email VARCHAR(100)" +
                                        ")";
            stmt.executeUpdate(createDoctorsTable);
            
            // Create Appointments table
            String createAppointmentsTable = "CREATE TABLE IF NOT EXISTS appointments (" +
                                            "appointment_id INT AUTO_INCREMENT PRIMARY KEY, " +
                                            "patient_id INT, " +
                                            "doctor_id INT, " +
                                            "appointment_date DATE, " +
                                            "appointment_time TIME, " +
                                            "status VARCHAR(20) DEFAULT 'Scheduled', " +
                                            "notes TEXT, " +
                                            "FOREIGN KEY (patient_id) REFERENCES patients(patient_id) ON DELETE CASCADE, " +
                                            "FOREIGN KEY (doctor_id) REFERENCES doctors(doctor_id) ON DELETE CASCADE" +
                                            ")";
            stmt.executeUpdate(createAppointmentsTable);
            
            stmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null, "Error creating tables: " + e.getMessage());
        }
    }
    
    // Helper methods
    private void loadPatientsIntoCombo(JComboBox<ComboItem> comboBox) {
        try {
            comboBox.removeAllItems();
            
            String query = "SELECT patient_id, name FROM patients ORDER BY name";
            PreparedStatement pstmt = connection.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery();
            
            while (rs.next()) {
                comboBox.addItem(new ComboItem(rs.getInt("patient_id"), rs.getString("name")));
            }
            
            rs.close();
            pstmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading patients: " + e.getMessage());
        }
    }
    
    private void loadDoctorsIntoCombo(JComboBox<ComboItem> comboBox) {
        try {
            comboBox.removeAllItems();
            
            String query = "SELECT doctor_id, name FROM doctors ORDER BY name";
            PreparedStatement pstmt = connection.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery();
            
            while (rs.next()) {
                comboBox.addItem(new ComboItem(rs.getInt("doctor_id"), rs.getString("name")));
            }
            
            rs.close();
            pstmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading doctors: " + e.getMessage());
        }
    }
    
    private void setSelectedComboItem(JComboBox<ComboItem> comboBox, int id) {
        for (int i = 0; i < comboBox.getItemCount(); i++) {
            ComboItem item = comboBox.getItemAt(i);
            if (item.getId() == id) {
                comboBox.setSelectedIndex(i);
                break;
            }
        }
    }
    
    private void deleteAppointment(int appointmentId) {
        try {
            // Delete appointment from database
            String query = "DELETE FROM appointments WHERE appointment_id = ?";
            PreparedStatement pstmt = connection.prepareStatement(query);
            pstmt.setInt(1, appointmentId);
            
            int rowsAffected = pstmt.executeUpdate();
            pstmt.close();
            
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(mainFrame, "Appointment deleted successfully!");
                loadAppointments(); // Refresh table
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Failed to delete appointment.");
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error deleting appointment: " + e.getMessage());
        }
    }
    
    private void deletePatient(int patientId) {
        try {
            // Check if patient has appointments
            String checkQuery = "SELECT COUNT(*) FROM appointments WHERE patient_id = ?";
            PreparedStatement checkStmt = connection.prepareStatement(checkQuery);
            checkStmt.setInt(1, patientId);
            ResultSet checkRs = checkStmt.executeQuery();
            checkRs.next();
            int appointmentCount = checkRs.getInt(1);
            checkRs.close();
            checkStmt.close();
            
            if (appointmentCount > 0) {
                int option = JOptionPane.showConfirmDialog(mainFrame, 
                    "This patient has " + appointmentCount + " appointment(s). Deleting the patient will also delete all their appointments. Continue?",
                    "Confirm Deletion", JOptionPane.YES_NO_OPTION);
                
                if (option != JOptionPane.YES_OPTION) {
                    return;
                }
            }
            
            // Delete patient from database
            String query = "DELETE FROM patients WHERE patient_id = ?";
            PreparedStatement pstmt = connection.prepareStatement(query);
            pstmt.setInt(1, patientId);
            
            int rowsAffected = pstmt.executeUpdate();
            pstmt.close();
            
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(mainFrame, "Patient deleted successfully!");
                loadPatients(); // Refresh patients table
                loadAppointments(); // Refresh appointments table since they might be affected
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Failed to delete patient.");
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error deleting patient: " + e.getMessage());
        }
    }
    
    private void deleteDoctor(int doctorId) {
        try {
            // Check if doctor has appointments
            String checkQuery = "SELECT COUNT(*) FROM appointments WHERE doctor_id = ?";
            PreparedStatement checkStmt = connection.prepareStatement(checkQuery);
            checkStmt.setInt(1, doctorId);
            ResultSet checkRs = checkStmt.executeQuery();
            checkRs.next();
            int appointmentCount = checkRs.getInt(1);
            checkRs.close();
            checkStmt.close();
            
            if (appointmentCount > 0) {
                int option = JOptionPane.showConfirmDialog(mainFrame, 
                    "This doctor has " + appointmentCount + " appointment(s). Deleting the doctor will also delete all their appointments. Continue?",
                    "Confirm Deletion", JOptionPane.YES_NO_OPTION);
                
                if (option != JOptionPane.YES_OPTION) {
                    return;
                }
            }
            
            // Delete doctor from database
            String query = "DELETE FROM doctors WHERE doctor_id = ?";
            PreparedStatement pstmt = connection.prepareStatement(query);
            pstmt.setInt(1, doctorId);
            
            int rowsAffected = pstmt.executeUpdate();
            pstmt.close();
            
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(mainFrame, "Doctor deleted successfully!");
                loadDoctors(); // Refresh doctors table
                loadAppointments(); // Refresh appointments table since they might be affected
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Failed to delete doctor.");
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error deleting doctor: " + e.getMessage());
        }
    }
    
    private void createGUI() {
        // Main frame setup
        mainFrame = new JFrame("Healthcare Appointment System");
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setSize(900, 600);
        mainFrame.setLocationRelativeTo(null);
        
        // Main panel with tabbed pane
        mainPanel = new JPanel(new BorderLayout());
        tabbedPane = new JTabbedPane();
        
        // Create tabs
        createAppointmentsTab();
        createPatientsTab();
        createDoctorsTab();
        
        // Add tabs to tabbed pane
        tabbedPane.addTab("Appointments", appointmentsPanel);
        tabbedPane.addTab("Patients", patientsPanel);
        tabbedPane.addTab("Doctors", doctorsPanel);
        
        // Add tabbed pane to main panel
        mainPanel.add(tabbedPane, BorderLayout.CENTER);
        
        // Set main panel as content pane
        mainFrame.setContentPane(mainPanel);
        mainFrame.setVisible(true);
    }
    
    private void createAppointmentsTab() {
        appointmentsPanel = new JPanel(new BorderLayout());
        
        // Create table model with column names
        String[] columnNames = {"ID", "Patient", "Doctor", "Date", "Time", "Status", "Notes"};
        appointmentsTableModel = new DefaultTableModel(columnNames, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false; // Make table non-editable
            }
            
            @Override
            public Class<?> getColumnClass(int columnIndex) {
                if (columnIndex == 0) return Integer.class;
                return Object.class;
            }
        };
        
        // Create table with the model
        appointmentsTable = new JTable(appointmentsTableModel);
        appointmentsTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        JScrollPane scrollPane = new JScrollPane(appointmentsTable);
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        addAppointmentBtn = new JButton("Add Appointment");
        updateAppointmentBtn = new JButton("Update Appointment");
        deleteAppointmentBtn = new JButton("Delete Appointment");
        
        // Add action listeners to buttons
        addAppointmentBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showAddAppointmentDialog();
            }
        });
        
        updateAppointmentBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = appointmentsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int appointmentId = Integer.parseInt(appointmentsTable.getValueAt(selectedRow, 0).toString());
                    showUpdateAppointmentDialog(appointmentId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select an appointment to update.");
                }
            }
        });
        
        deleteAppointmentBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = appointmentsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int appointmentId = Integer.parseInt(appointmentsTable.getValueAt(selectedRow, 0).toString());
                    deleteAppointment(appointmentId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select an appointment to delete.");
                }
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(addAppointmentBtn);
        buttonsPanel.add(updateAppointmentBtn);
        buttonsPanel.add(deleteAppointmentBtn);
        
        // Add components to appointments panel
        appointmentsPanel.add(scrollPane, BorderLayout.CENTER);
        appointmentsPanel.add(buttonsPanel, BorderLayout.SOUTH);
    }
    
    private void createPatientsTab() {
        patientsPanel = new JPanel(new BorderLayout());
        
        // Create table model with column names
        String[] columnNames = {"ID", "Name", "Gender", "DOB", "Phone", "Email", "Address"};
        patientsTableModel = new DefaultTableModel(columnNames, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false; // Make table non-editable
            }
        };
        
        // Create table with the model
        patientsTable = new JTable(patientsTableModel);
        patientsTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        JScrollPane scrollPane = new JScrollPane(patientsTable);
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        addPatientBtn = new JButton("Add Patient");
        updatePatientBtn = new JButton("Update Patient");
        deletePatientBtn = new JButton("Delete Patient");
        
        // Add action listeners to buttons
        addPatientBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showAddPatientDialog();
            }
        });
        
        updatePatientBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = patientsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int patientId = Integer.parseInt(patientsTable.getValueAt(selectedRow, 0).toString());
                    showUpdateAppointmentDialog(patientId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select a patient to update.");
                }
            }
        });
        
        deletePatientBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = patientsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int patientId = Integer.parseInt(patientsTable.getValueAt(selectedRow, 0).toString());
                    deletePatient(patientId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select a patient to delete.");
                }
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(addPatientBtn);
        buttonsPanel.add(updatePatientBtn);
        buttonsPanel.add(deletePatientBtn);
        
        // Add components to patients panel
        patientsPanel.add(scrollPane, BorderLayout.CENTER);
        patientsPanel.add(buttonsPanel, BorderLayout.SOUTH);
    }
    
    private void createDoctorsTab() {
        doctorsPanel = new JPanel(new BorderLayout());
        
        // Create table model with column names
        String[] columnNames = {"ID", "Name", "Specialization", "Phone", "Email"};
        doctorsTableModel = new DefaultTableModel(columnNames, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false; // Make table non-editable
            }
        };
        
        // Create table with the model
        doctorsTable = new JTable(doctorsTableModel);
        doctorsTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        JScrollPane scrollPane = new JScrollPane(doctorsTable);
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        addDoctorBtn = new JButton("Add Doctor");
        updateDoctorBtn = new JButton("Update Doctor");
        deleteDoctorBtn = new JButton("Delete Doctor");
        
        // Add action listeners to buttons
        addDoctorBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showAddDoctorDialog();
            }
        });
        
        updateDoctorBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = doctorsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int doctorId = Integer.parseInt(doctorsTable.getValueAt(selectedRow, 0).toString());
                    showUpdateAppointmentDialog(doctorId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select a doctor to update.");
                }
            }
        });
        
        deleteDoctorBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = doctorsTable.getSelectedRow();
                if (selectedRow >= 0) {
                    int doctorId = Integer.parseInt(doctorsTable.getValueAt(selectedRow, 0).toString());
                    deleteDoctor(doctorId);
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Please select a doctor to delete.");
                }
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(addDoctorBtn);
        buttonsPanel.add(updateDoctorBtn);
        buttonsPanel.add(deleteDoctorBtn);
        
        // Add components to doctors panel
        doctorsPanel.add(scrollPane, BorderLayout.CENTER);
        doctorsPanel.add(buttonsPanel, BorderLayout.SOUTH);
    }
    
    // Database operations
    private void loadAppointments() {
        try {
            // Clear existing data
            appointmentsTableModel.setRowCount(0);
            
            // Prepare SQL query
            String query = "SELECT a.appointment_id, p.name AS patient_name, d.name AS doctor_name, " +
                          "a.appointment_date, a.appointment_time, a.status, a.notes " +
                          "FROM appointments a " +
                          "JOIN patients p ON a.patient_id = p.patient_id " +
                          "JOIN doctors d ON a.doctor_id = d.doctor_id " +
                          "ORDER BY a.appointment_date, a.appointment_time";
            
            PreparedStatement pstmt = connection.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery();
            
            // Add data to table model
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("appointment_id"),
                    rs.getString("patient_name"),
                    rs.getString("doctor_name"),
                    rs.getDate("appointment_date"),
                    rs.getTime("appointment_time"),
                    rs.getString("status"),
                    rs.getString("notes")
                };
                appointmentsTableModel.addRow(row);
            }
            
            rs.close();
            pstmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading appointments: " + e.getMessage());
        }
    }
    
    private void loadPatients() {
        try {
            // Clear existing data
            patientsTableModel.setRowCount(0);
            
            // Prepare SQL query
            String query = "SELECT * FROM patients ORDER BY name";
            
            PreparedStatement pstmt = connection.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery();
            
            // Add data to table model
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("patient_id"),
                    rs.getString("name"),
                    rs.getString("gender"),
                    rs.getDate("dob"),
                    rs.getString("phone"),
                    rs.getString("email"),
                    rs.getString("address")
                };
                patientsTableModel.addRow(row);
            }
            
            rs.close();
            pstmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading patients: " + e.getMessage());
        }
    }
    
    private void loadDoctors() {
        try {
            // Clear existing data
            doctorsTableModel.setRowCount(0);
            
            // Prepare SQL query
            String query = "SELECT * FROM doctors ORDER BY name";
            
            PreparedStatement pstmt = connection.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery();
            
            // Add data to table model
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("doctor_id"),
                    rs.getString("name"),
                    rs.getString("specialization"),
                    rs.getString("phone"),
                    rs.getString("email")
                };
                doctorsTableModel.addRow(row);
            }
            
            rs.close();
            pstmt.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading doctors: " + e.getMessage());
        }
    }
    
    // Add operations
    private void showAddAppointmentDialog() {
        JDialog dialog = new JDialog(mainFrame, "Add New Appointment", true);
        dialog.setLayout(new BorderLayout());
        dialog.setSize(400, 350);
        dialog.setLocationRelativeTo(mainFrame);
        
        JPanel formPanel = new JPanel(new GridLayout(7, 2, 5, 5));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        // Form fields
        JComboBox<ComboItem> patientCombo = new JComboBox<>();
        JComboBox<ComboItem> doctorCombo = new JComboBox<>();
        JTextField dateField = new JTextField();
        JTextField timeField = new JTextField();
        JComboBox<String> statusCombo = new JComboBox<>(new String[] {"Scheduled", "Completed", "Cancelled"});
        JTextArea notesArea = new JTextArea(3, 20);
        
        // Load patients and doctors into combo boxes
        loadPatientsIntoCombo(patientCombo);
        loadDoctorsIntoCombo(doctorCombo);
        
        // Add form fields to panel
        formPanel.add(new JLabel("Patient:"));
        formPanel.add(patientCombo);
        formPanel.add(new JLabel("Doctor:"));
        formPanel.add(doctorCombo);
        formPanel.add(new JLabel("Date (YYYY-MM-DD):"));
        formPanel.add(dateField);
        formPanel.add(new JLabel("Time (HH:MM):"));
        formPanel.add(timeField);
        formPanel.add(new JLabel("Status:"));
        formPanel.add(statusCombo);
        formPanel.add(new JLabel("Notes:"));
        formPanel.add(new JScrollPane(notesArea));
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");
        
        // Add action listeners to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Validate input
                    if (patientCombo.getSelectedIndex() == -1 || doctorCombo.getSelectedIndex() == -1 ||
                        dateField.getText().trim().isEmpty() || timeField.getText().trim().isEmpty()) {
                        JOptionPane.showMessageDialog(dialog, "Please fill all required fields.");
                        return;
                    }
                    
                    // Get selected patient and doctor IDs
                    ComboItem selectedPatient = (ComboItem) patientCombo.getSelectedItem();
                    ComboItem selectedDoctor = (ComboItem) doctorCombo.getSelectedItem();
                    
                    // Validate date format
                    SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
                    dateFormat.setLenient(false);
                    Date parsedDate = dateFormat.parse(dateField.getText().trim());
                    
                    // Validate time format
                    SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm");
                    timeFormat.setLenient(false);
                    Date parsedTime = timeFormat.parse(timeField.getText().trim());
                    
                    // Save appointment to database
                    String query = "INSERT INTO appointments (patient_id, doctor_id, appointment_date, appointment_time, status, notes) " +
                                  "VALUES (?, ?, ?, ?, ?, ?)";
                    
                    PreparedStatement pstmt = connection.prepareStatement(query);
                    pstmt.setInt(1, selectedPatient.getId());
                    pstmt.setInt(2, selectedDoctor.getId());
                    pstmt.setDate(3, new java.sql.Date(parsedDate.getTime()));
                    pstmt.setTime(4, new java.sql.Time(parsedTime.getTime()));
                    pstmt.setString(5, statusCombo.getSelectedItem().toString());
                    pstmt.setString(6, notesArea.getText().trim());
                    
                    int rowsAffected = pstmt.executeUpdate();
                    pstmt.close();
                    
                    if (rowsAffected > 0) {
                        JOptionPane.showMessageDialog(dialog, "Appointment added successfully!");
                        dialog.dispose();
                        loadAppointments(); // Refresh table
                    } else {
                        JOptionPane.showMessageDialog(dialog, "Failed to add appointment.");
                    }
                    
                } catch (ParseException ex) {
                    JOptionPane.showMessageDialog(dialog, "Invalid date or time format. Please use YYYY-MM-DD and HH:MM formats.");
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(dialog, "Database error: " + ex.getMessage());
                }
            }
        });
        
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.dispose();
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(saveButton);
        buttonsPanel.add(cancelButton);
        
        // Add panels to dialog
        dialog.add(formPanel, BorderLayout.CENTER);
        dialog.add(buttonsPanel, BorderLayout.SOUTH);
        
        dialog.setVisible(true);
    }
    
    private void showAddPatientDialog() {
        JDialog dialog = new JDialog(mainFrame, "Add New Patient", true);
        dialog.setLayout(new BorderLayout());
        dialog.setSize(400, 300);
        dialog.setLocationRelativeTo(mainFrame);
        
        JPanel formPanel = new JPanel(new GridLayout(6, 2, 5, 5));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        // Form fields
        JTextField nameField = new JTextField();
        JComboBox<String> genderCombo = new JComboBox<>(new String[] {"Male", "Female", "Other"});
        JTextField dobField = new JTextField();
        JTextField phoneField = new JTextField();
        JTextField emailField = new JTextField();
        JTextField addressField = new JTextField();
        
        // Add form fields to panel
        formPanel.add(new JLabel("Name:"));
        formPanel.add(nameField);
        formPanel.add(new JLabel("Gender:"));
        formPanel.add(genderCombo);
        formPanel.add(new JLabel("Date of Birth (YYYY-MM-DD):"));
        formPanel.add(dobField);
        formPanel.add(new JLabel("Phone:"));
        formPanel.add(phoneField);
        formPanel.add(new JLabel("Email:"));
        formPanel.add(emailField);
        formPanel.add(new JLabel("Address:"));
        formPanel.add(addressField);
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");
        
        // Add action listeners to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Validate input
                    if (nameField.getText().trim().isEmpty()) {
                        JOptionPane.showMessageDialog(dialog, "Name is required.");
                        return;
                    }
                    
                    // Validate date format if provided
                    java.sql.Date sqlDate = null;
                    if (!dobField.getText().trim().isEmpty()) {
                        try {
                            SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
                            dateFormat.setLenient(false);
                            Date parsedDate = dateFormat.parse(dobField.getText().trim());
                            sqlDate = new java.sql.Date(parsedDate.getTime());
                        } catch (ParseException ex) {
                            JOptionPane.showMessageDialog(dialog, "Invalid date format. Please use YYYY-MM-DD format.");
                            return;
                        }
                    }
                    
                    // Save patient to database
                    String query = "INSERT INTO patients (name, gender, dob, phone, email, address) " +
                                  "VALUES (?, ?, ?, ?, ?, ?)";
                    
                    PreparedStatement pstmt = connection.prepareStatement(query);
                    pstmt.setString(1, nameField.getText().trim());
                    pstmt.setString(2, genderCombo.getSelectedItem().toString());
                    
                    if (sqlDate != null) {
                        pstmt.setDate(3, sqlDate);
                    } else {
                        pstmt.setNull(3, Types.DATE);
                    }
                    
                    pstmt.setString(4, phoneField.getText().trim());
                    pstmt.setString(5, emailField.getText().trim());
                    pstmt.setString(6, addressField.getText().trim());
                    
                    int rowsAffected = pstmt.executeUpdate();
                    pstmt.close();
                    
                    if (rowsAffected > 0) {
                        JOptionPane.showMessageDialog(dialog, "Patient added successfully!");
                        dialog.dispose();
                        loadPatients(); // Refresh table
                    } else {
                        JOptionPane.showMessageDialog(dialog, "Failed to add patient.");
                    }
                    
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(dialog, "Database error: " + ex.getMessage());
                }
            }
        });
        
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.dispose();
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(saveButton);
        buttonsPanel.add(cancelButton);
        
        // Add panels to dialog
        dialog.add(formPanel, BorderLayout.CENTER);
        dialog.add(buttonsPanel, BorderLayout.SOUTH);
        
        dialog.setVisible(true);
    }
    
    private void showAddDoctorDialog() {
        JDialog dialog = new JDialog(mainFrame, "Add New Doctor", true);
        dialog.setLayout(new BorderLayout());
        dialog.setSize(400, 250);
        dialog.setLocationRelativeTo(mainFrame);
        
        JPanel formPanel = new JPanel(new GridLayout(4, 2, 5, 5));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        // Form fields
        JTextField nameField = new JTextField();
        JTextField specializationField = new JTextField();
        JTextField phoneField = new JTextField();
        JTextField emailField = new JTextField();
        
        // Add form fields to panel
        formPanel.add(new JLabel("Name:"));
        formPanel.add(nameField);
        formPanel.add(new JLabel("Specialization:"));
        formPanel.add(specializationField);
        formPanel.add(new JLabel("Phone:"));
        formPanel.add(phoneField);
        formPanel.add(new JLabel("Email:"));
        formPanel.add(emailField);
        
        // Create buttons panel
        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");
        
        // Add action listeners to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    // Validate input
                    if (nameField.getText().trim().isEmpty()) {
                        JOptionPane.showMessageDialog(dialog, "Name is required.");
                        return;
                    }
                    
                    // Save doctor to database
                    String query = "INSERT INTO doctors (name, specialization, phone, email) " +
                                  "VALUES (?, ?, ?, ?)";
                    
                    PreparedStatement pstmt = connection.prepareStatement(query);
                    pstmt.setString(1, nameField.getText().trim());
                    pstmt.setString(2, specializationField.getText().trim());
                    pstmt.setString(3, phoneField.getText().trim());
                    pstmt.setString(4, emailField.getText().trim());
                    
                    int rowsAffected = pstmt.executeUpdate();
                    pstmt.close();
                    
                    if (rowsAffected > 0) {
                        JOptionPane.showMessageDialog(dialog, "Doctor added successfully!");
                        dialog.dispose();
                        loadDoctors(); // Refresh table
                    } else {
                        JOptionPane.showMessageDialog(dialog, "Failed to add doctor.");
                    }
                    
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(dialog, "Database error: " + ex.getMessage());
                }
            }
        });
        
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.dispose();
            }
        });
        
        // Add buttons to panel
        buttonsPanel.add(saveButton);
        buttonsPanel.add(cancelButton);
        
        // Add panels to dialog
        dialog.add(formPanel, BorderLayout.CENTER);
        dialog.add(buttonsPanel, BorderLayout.SOUTH);
        
        dialog.setVisible(true);
    }
    
    // Update operations
    private void showUpdateAppointmentDialog(int appointmentId) {
        try {
            // Get appointment data
            String query = "SELECT * FROM appointments WHERE appointment_id = ?";
            PreparedStatement pstmt = connection.prepareStatement(query);
            pstmt.setInt(1, appointmentId);
            ResultSet rs = pstmt.executeQuery();
            
            if (rs.next()) {
                JDialog dialog = new JDialog(mainFrame, "Update Appointment", true);
                dialog.setLayout(new BorderLayout());
                dialog.setSize(400, 350);
                dialog.setLocationRelativeTo(mainFrame);
                
                JPanel formPanel = new JPanel(new GridLayout(7, 2, 5, 5));
                formPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
                
                // Form fields
                JComboBox<ComboItem> patientCombo = new JComboBox<>();
                JComboBox<ComboItem> doctorCombo = new JComboBox<>();
                JTextField dateField = new JTextField();
                JTextField timeField = new JTextField();
                JComboBox<String> statusCombo = new JComboBox<>(new String[] {"Scheduled", "Completed", "Cancelled"});
                JTextArea notesArea = new JTextArea(3, 20);
                
                // Load patients and doctors into combo boxes
                loadPatientsIntoCombo(patientCombo);
                loadDoctorsIntoCombo(doctorCombo);
                
                // Set current values
                int patientId = rs.getInt("patient_id");
                int doctorId = rs.getInt("doctor_id");
                setSelectedComboItem(patientCombo, patientId);
                setSelectedComboItem(doctorCombo, doctorId);
                
                Date appointmentDate = rs.getDate("appointment_date");
                Time appointmentTime = rs.getTime("appointment_time");
                
                SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
                SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm");
                
                dateField.setText(appointmentDate != null ? dateFormat.format(appointmentDate) : "");
                timeField.setText(appointmentTime != null ? timeFormat.format(appointmentTime) : "");
                
                String status = rs.getString("status");
                for (int i = 0; i < statusCombo.getItemCount(); i++) {
                    if (statusCombo.getItemAt(i).equals(status)) {
                        statusCombo.setSelectedIndex(i);
                        break;
                    }
                }
                
                notesArea.setText(rs.getString("notes"));
                
                // Add form fields to panel
                formPanel.add(new JLabel("Patient:"));
                formPanel.add(patientCombo);
                formPanel.add(new JLabel("Doctor:"));
                formPanel.add(doctorCombo);
                formPanel.add(new JLabel("Date (YYYY-MM-DD):"));
                formPanel.add(dateField);
                formPanel.add(new JLabel("Time (HH:MM):"));
                formPanel.add(timeField);
                formPanel.add(new JLabel("Status:"));
                formPanel.add(statusCombo);
                formPanel.add(new JLabel("Notes:"));
                formPanel.add(new JScrollPane(notesArea));
                
                // Create buttons panel
                JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
                JButton saveButton = new JButton("Save");
                JButton cancelButton = new JButton("Cancel");
                
                // Add action listeners to buttons
                saveButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        try {
                            // Validate input
                            if (patientCombo.getSelectedIndex() == -1 || doctorCombo.getSelectedIndex() == -1 ||
                                dateField.getText().trim().isEmpty() || timeField.getText().trim().isEmpty()) {
                                JOptionPane.showMessageDialog(dialog, "Please fill all required fields.");
                                return;
                            }
                            
                            // Get selected patient and doctor IDs
                            ComboItem selectedPatient = (ComboItem) patientCombo.getSelectedItem();
                            ComboItem selectedDoctor = (ComboItem) doctorCombo.getSelectedItem();
                            
                            // Validate date format
                            SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
                            dateFormat.setLenient(false);
                            Date parsedDate = dateFormat.parse(dateField.getText().trim());
                            
                            // Validate time format
                            SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm");
                            timeFormat.setLenient(false);
                            Date parsedTime = timeFormat.parse(timeField.getText().trim());
                            
                            // Update appointment in database
                            String updateQuery = "UPDATE appointments SET patient_id = ?, doctor_id = ?, " +
                                              "appointment_date = ?, appointment_time = ?, status = ?, notes = ? " +
                                              "WHERE appointment_id = ?";
                            
                            PreparedStatement updateStmt = connection.prepareStatement(updateQuery);
                            updateStmt.setInt(1, selectedPatient.getId());
                            updateStmt.setInt(2, selectedDoctor.getId());
                            updateStmt.setDate(3, new java.sql.Date(parsedDate.getTime()));
                            updateStmt.setTime(4, new java.sql.Time(parsedTime.getTime()));
                            updateStmt.setString(5, statusCombo.getSelectedItem().toString());
                            updateStmt.setString(6, notesArea.getText().trim());
                            updateStmt.setInt(7, appointmentId);
                            
                            int rowsAffected = updateStmt.executeUpdate();
                            updateStmt.close();
                            
                            if (rowsAffected > 0) {
                                JOptionPane.showMessageDialog(dialog, "Appointment updated successfully!");
                                dialog.dispose();
                                loadAppointments(); // Refresh table
                            } else {
                                JOptionPane.showMessageDialog(dialog, "Failed to update appointment.");
                            }
                            
                        } catch (ParseException ex) {
                            JOptionPane.showMessageDialog(dialog, "Invalid date or time format. Please use YYYY-MM-DD and HH:MM formats.");
                        } catch (SQLException ex) {
                            JOptionPane.showMessageDialog(dialog, "Database error: " + ex.getMessage());
                        }
                    }
                });
                
                cancelButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        dialog.dispose();
                    }
                });
                
                // Add buttons to panel
                buttonsPanel.add(saveButton);
                buttonsPanel.add(cancelButton);
                
                // Add panels to dialog
                dialog.add(formPanel, BorderLayout.CENTER);
                dialog.add(buttonsPanel, BorderLayout.SOUTH);
                
                dialog.setVisible(true);
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Appointment not found.");
            }
            
            rs.close();
            pstmt.close();
            
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(mainFrame, "Error loading appointment data: " + e.getMessage());
        }
    }
}