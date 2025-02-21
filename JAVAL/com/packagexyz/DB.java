package com.packagexyz;
public class DB {
    public int code;
    public String clg_name;
    public int placed_students;
    int getCode(){
        return this.code;
    }
    String getClgName(){
        return this.clg_name;
    }
    int getPlacementRecord(){
        return this.placed_students;
    }

    void setCode(int code){
        this.code = code;
    }
    void setClgName(String clg_name){
        this.clg_name = clg_name;
    }
    void setPlacementRecords(){
        this.placed_students = placed_students;
    }
}
