import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
<applet code="LoginSignupApplet" width=500 height=400>
</applet>
*/

public class LoginSignupApplet extends Applet implements ActionListener {
    // Components for Login Form
    Label loginLabel, loginUsernameLabel, loginPasswordLabel;
    TextField loginUsernameField, loginPasswordField;
    Button loginButton, switchToSignupButton;

    // Components for Signup Form
    Label signupLabel, signupUsernameLabel, signupPasswordLabel, signupConfirmPasswordLabel;
    TextField signupUsernameField, signupPasswordField, signupConfirmPasswordField;
    Button signupButton, switchToLoginButton;

    // Status Label
    Label statusLabel;

    // Current form state
    boolean isLoginForm = true;

    public void init() {
        setLayout(null);

        // Initialize Login Form Components
        loginLabel = new Label("Login Form");
        loginLabel.setBounds(200, 30, 100, 30);

        loginUsernameLabel = new Label("Username:");
        loginUsernameLabel.setBounds(100, 80, 100, 30);
        loginUsernameField = new TextField();
        loginUsernameField.setBounds(200, 80, 150, 30);

        loginPasswordLabel = new Label("Password:");
        loginPasswordLabel.setBounds(100, 130, 100, 30);
        loginPasswordField = new TextField();
        loginPasswordField.setEchoChar('*');
        loginPasswordField.setBounds(200, 130, 150, 30);

        loginButton = new Button("Login");
        loginButton.setBounds(150, 180, 80, 30);
        loginButton.addActionListener(this);

        switchToSignupButton = new Button("Signup");
        switchToSignupButton.setBounds(250, 180, 80, 30);
        switchToSignupButton.addActionListener(this);

        // Initialize Signup Form Components
        signupLabel = new Label("Signup Form");
        signupLabel.setBounds(200, 30, 100, 30);

        signupUsernameLabel = new Label("Username:");
        signupUsernameLabel.setBounds(100, 80, 100, 30);
        signupUsernameField = new TextField();
        signupUsernameField.setBounds(200, 80, 150, 30);

        signupPasswordLabel = new Label("Password:");
        signupPasswordLabel.setBounds(100, 130, 100, 30);
        signupPasswordField = new TextField();
        signupPasswordField.setEchoChar('*');
        signupPasswordField.setBounds(200, 130, 150, 30);

        signupConfirmPasswordLabel = new Label("Confirm Password:");
        signupConfirmPasswordLabel.setBounds(100, 180, 120, 30);
        signupConfirmPasswordField = new TextField();
        signupConfirmPasswordField.setEchoChar('*');
        signupConfirmPasswordField.setBounds(230, 180, 150, 30);

        signupButton = new Button("Signup");
        signupButton.setBounds(150, 230, 80, 30);
        signupButton.addActionListener(this);

        switchToLoginButton = new Button("Login");
        switchToLoginButton.setBounds(250, 230, 80, 30);
        switchToLoginButton.addActionListener(this);

        // Status Label
        statusLabel = new Label("");
        statusLabel.setBounds(100, 280, 300, 30);
        statusLabel.setAlignment(Label.CENTER);

        // Add Login Form Components by default
        add(loginLabel);
        add(loginUsernameLabel);
        add(loginUsernameField);
        add(loginPasswordLabel);
        add(loginPasswordField);
        add(loginButton);
        add(switchToSignupButton);
        add(statusLabel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == loginButton) {
            String username = loginUsernameField.getText();
            String password = loginPasswordField.getText();

            if (username.equals("admin") && password.equals("password")) {
                statusLabel.setText("Login Successful!");
            } else {
                statusLabel.setText("Invalid Username or Password!");
            }
        } else if (e.getSource() == switchToSignupButton) {
            switchToSignupForm();
        } else if (e.getSource() == signupButton) {
            String username = signupUsernameField.getText();
            String password = signupPasswordField.getText();
            String confirmPassword = signupConfirmPasswordField.getText();

            if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
                statusLabel.setText("All fields are required!");
            } else if (!password.equals(confirmPassword)) {
                statusLabel.setText("Passwords do not match!");
            } else {
                statusLabel.setText("Signup Successful! Please Login.");
                switchToLoginForm();
            }
        } else if (e.getSource() == switchToLoginButton) {
            switchToLoginForm();
        }
    }

    private void switchToSignupForm() {
        removeAll();
        add(signupLabel);
        add(signupUsernameLabel);
        add(signupUsernameField);
        add(signupPasswordLabel);
        add(signupPasswordField);
        add(signupConfirmPasswordLabel);
        add(signupConfirmPasswordField);
        add(signupButton);
        add(switchToLoginButton);
        add(statusLabel);
        repaint();
    }

    private void switchToLoginForm() {
        removeAll();
        add(loginLabel);
        add(loginUsernameLabel);
        add(loginUsernameField);
        add(loginPasswordLabel);
        add(loginPasswordField);
        add(loginButton);
        add(switchToSignupButton);
        add(statusLabel);
        repaint();
    }
}
