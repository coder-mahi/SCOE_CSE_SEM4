import user_defined_exception.AgeException;
import user_defined_exception.InvalidInfoException;
import java.io.*;
class VoterDB {
    private int voterid;
    private String name;
    private int age;

    public void setVoterID(int voterid) throws InvalidInfoException{
        if (voterid<=0){
            throw new InvalidInfoException("Invalid Voter ID");
        }
        this.voterid =voterid;
    }

    public void setName(String name) throws InvalidInfoException{
        if(name==null ||name.isEmpty())
        {
            throw new InvalidInfoException("Invalid Name");
        }
        this.name=name;
    }

    public void setAge(int age) throws AgeException{
        if(age<18){
            throw new AgeException(age);
        }
        this.age =age;
    }
    public int getVoterID(){
        return voterid;
    }

    public String getName(){
        return name;
    }

    public int getAge(){
        return age;
    }
}

public class Assignment5{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        VoterDB voter = new VoterDB();
        
        try {
            System.out.print("Enter Voter ID: ");
            int voterid = Integer.parseInt(br.readLine());
            voter.setVoterID(voterid);

            System.out.print("Enter Name: ");
            String name = br.readLine();
            voter.setName(name);

            System.out.print("Enter Age: ");
            int age = Integer.parseInt(br.readLine());
            voter.setAge(age);

            System.out.println("Voter Details:");
            System.out.println("Voter ID: " + voter.getVoterID());
            System.out.println("Name: " + voter.getName());
            System.out.println("Age: " + voter.getAge());

        } 
        catch(InvalidInfoException | AgeException e){
            System.out.println("Error: " + e.getMessage());
        } 
        catch(NumberFormatException e){
            System.out.println("Error: Invalid input format");
        }
    }
}