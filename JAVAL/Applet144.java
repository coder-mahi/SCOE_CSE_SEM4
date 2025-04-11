import java.awt.Button;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.*;
import javax.swing.JApplet;
import java.applet.*;
import java.awt.Graphics;

import java.sql.*;

public class Applet144 extends JApplet implements ActionListener 
{
    Label l1,l2,l3,l4;
    TextField t1,t2,t3,t4;
    Button b1,b2;
    Label status;
    String displayText="";

    public void init() {
        setLayout(new FlowLayout());
        l1 = new Label("Username: ");
        l2 = new Label("Email: ");
        l3 = new Label("Password:");
        l4 =new Label("Confirm pwd: ");
        t1 = new TextField(50);
        t2 = new TextField(50);
        t3 =new TextField(50);
        t4 = new TextField(50);
        
        b1 =new Button("SIgn up");
        b2 =new Button("Cancel");

        status = new Label();
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(l4);
        add(t4);
        add(b1);
        add(b2);
        add(status);

        b1.addActionListener(this);
        b2.addActionListener(this);
    }

    public void paint(Graphics g) 
    {
        g.drawString(displayText,500,500);
    }

    public void actionPerformed(ActionEvent e) {
        String s1 = t1.getText();
        String s2 = t2.getText();
        String s3 =t3.getText();
        String s4 =t4.getText();

        if (e.getSource() == b1) {
            if (s1.equals("") ||s2.equals("") ||s3.equals("") ||s4.equals("")){
                displayText ="Enter all fields correct...";
                status.setText("Enter all fields correct...");
            } 
            else if(!s3.equals(s4)) 
            {
                displayText ="Passwords do not match..";
                status.setText("Passwords do not match!");
            }
            else{
                displayText ="Registered successfulltyy!";
                status.setText("Registered succesfully..! Username: "+s1+", Email:"+s2);
            }

        } else if(e.getSource() ==b2) {
            t1.setText("");
            t2.setText("");
            t3.setText("");
            t4.setText("");
            displayText ="Form cleared.";
            status.setText("Form cleared!");
        }
        repaint();
    }
}
