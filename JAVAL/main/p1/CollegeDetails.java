package main.p1;
public interface CollegeDetails
{
    public static final int roll_no=0;
    public static final int fid=0;
    public static final String faculty_name="";

    public static final String student_name="";
    public static final boolean isStudentPlaced = false;
    public void setStudName(String student_name);
    public void setStudRoll(int roll_no);

    public int getRollNo();
    public String getStudName();

    public void setPlacedOrNot(boolean isStudentPlaced);
    public boolean getPlacedOrNot();

    public void setFacultyName(String student_name);
    public void setFacultyID(int roll_no);
    public int getFacultyID();
    
    public String getFacultyName();

}
