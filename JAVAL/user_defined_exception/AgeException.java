package user_defined_exception;

public class AgeException extends Exception{
    private int age = 0;
    public AgeException(int age){
        System.out.println(showException());
        this.age = age;
    }

    public String showException(){
        return "Age Exception :> "+age;
    }

}
