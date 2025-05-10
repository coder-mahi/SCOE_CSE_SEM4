import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

/*
<applet code="MyApplet" width=400 height=300>
</applet>
*/

public class MyApplet extends Applet implements ActionListener {
    Label label;
    TextField textField;
    Button button;

    public void init() {
        // Set layout
        setLayout(new FlowLayout());

        // Initialize components
        label = new Label("Enter your name:");
        textField = new TextField(20);
        button = new Button("Submit");

        // Add action listener to button
        button.addActionListener(this);

        // Add components to applet
        add(label);
        add(textField);
        add(button);
    }

    public void actionPerformed(ActionEvent e) {
        String name = textField.getText();
        showStatus("Hello, " + name + "!");  // Displays message in applet's status bar
    }
}
