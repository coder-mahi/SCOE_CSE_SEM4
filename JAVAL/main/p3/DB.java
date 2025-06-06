package main.p3;
// import main.p1.*;
import main.p2.PlacementRecord;

public class DB implements PlacementRecord
{
    private String student_name ;
    private String faculty_name;

    private String clg_name;

    private int roll_no;
     private int faculty_id; 
    private int placed_students;

    private int clg_id;

    private boolean isStudentPlaced;
    
    @Override
    public void setStudName(String student_name)
    {
        this.student_name =student_name;
    }

    @Override
    public void setStudRoll(int roll_no)
    {
        this.roll_no =roll_no;
    }
    @Override
    public int getRollNo() {
        return roll_no;
    }

    @Override
    public String getStudName()
    {
        return student_name;
    }

    @Override
    public void setFacultyName(String student_name)
    {
         this.student_name=student_name;
    }
    @Override
    public void setFacultyID(int faculty_id){
        this.faculty_id=faculty_id;
    }

    @Override
    public int getFacultyID()
    {
        return faculty_id;
    }

    @Override
    public String getFacultyName(){
        return faculty_name;
    }
    
    @Override
    public int getPlacementRecord(){
        return placed_students;
    }
    @Override
    public void setCode(int clg_id){
        this.clg_id = clg_id;
    }
    @Override
    public void setClgName(String clg_name){
        this.clg_name = clg_name;
    }
    @Override
    public void setPlacementRecords(int placed_students){
        this.placed_students = placed_students;
    }
    @Override
    public int getCode() {
        return clg_id;
    }

    @Override
    public String getClgName() {
        return clg_name;
    }

    @Override
    public void setPlacedOrNot(boolean isStudentPlaced){
        this.isStudentPlaced = isStudentPlaced;
    }
    @Override
    public boolean getPlacedOrNot(){
        return isStudentPlaced;
    }



}