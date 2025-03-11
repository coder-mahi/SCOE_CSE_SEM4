package user_defined_exception;

public class AgeException extends Exception{
    private int age;

    public AgeException(int age){
        this.age = age;
        System.out.println(showException());
    }

    public String showException(){
        return "Age Exception Occurred :> "+age;
    }

}
