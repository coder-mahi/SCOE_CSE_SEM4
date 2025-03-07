package user_defined_exception;

public class InvalidInfoException extends Exception
{
    private String str = "";
    public InvalidInfoException(String str){
        this.str = str;
    }

    public String showException(){
        return "Occurred Exception :> "+str;
    }
}