package main.p2;
import main.p1.CollegeDetails;

public interface PlacementRecord extends CollegeDetails
{
    public static final int clgID=0;
    public static final String clg_name="";

    public static final int placed_students=0;

    public int getCode();
    public String getClgName();
    public int getPlacementRecord();

    public void setCode(int code);

    public void setClgName(String clg_name);
    public void setPlacementRecords(int placed_students);
}
