import java.sql.*;

public class JdbcPractice {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/dbms_practice";
        String username = "root";
        String password = "mahesh";

        try {
            // Load JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Connect to MySQL
            Connection con = DriverManager.getConnection(url, username, password);

            // Insert Query
            String insertQuery = "INSERT INTO TEST(ID, NAME, ADDRESS) VALUES (?, ?, ?)";
            PreparedStatement insertStmt = con.prepareStatement(insertQuery);
            insertStmt.setInt(1, 105);
            insertStmt.setString(2, "mahesh shinde");
            insertStmt.setString(3, "undirwadi");

            int rowsAffected = insertStmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Inserted successfully...!");
            }
            insertStmt.close();

            // Select Query
            String selectQuery = "SELECT * FROM TEST";
            Statement selectStmt = con.createStatement();
            ResultSet rs = selectStmt.executeQuery(selectQuery);

            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("ID"));
                System.out.println("Name: " + rs.getString("NAME"));
                System.out.println("Address: " + rs.getString("ADDRESS"));
                System.out.println("------------------------");
            }

            rs.close();
            selectStmt.close();
            con.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
