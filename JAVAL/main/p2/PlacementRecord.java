package main.p2;

public interface PlacementRecord {
    int clgID=0;
    String clg_name=""; 
    int placed_students=0;

    int getCode();
    String getClgName();
    int getPlacementRecord();
    void setCode(int code);
    void setClgName(String clg_name);
    void setPlacementRecords(int placed_students);
}
