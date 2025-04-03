package user_defined_exception;

public class InvalidInfoException extends Exception
{
    private String str = "";
    public InvalidInfoException(String str){
        this.str = str;
        System.out.println(showException());
    }

    public String showException(){
        return "Occurred Exception :> "+str;
    }
}