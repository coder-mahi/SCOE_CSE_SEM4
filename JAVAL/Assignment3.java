import java.util.*;
interface firstYear{
    final int max1 = 180;
    void calculateYear1();
}
interface secondYear{
    final int max2 =240;
    void calculateYear2();
}
interface thirdYear{
    final int max3 = 300;
    void calculateYear3();
}
interface DAO extends firstYear,secondYear,thirdYear{
    default String showMsg(){
        return "Calculating Aggregate Percentage :> ";
    }
}
class DAOImplementation implements DAO{
    private float o1,o2,o3;
    private float p1,p2,p3;
    private int s1,s2,s3;
    Scanner sc;
    private int getSubjectMarks(int size){
        sc = new Scanner(System.in);
         int[] arr = new int[size];
        int total = 0;
        System.out.println("ENter marks of "+size+" subjects..(<=60)");
        for(int i=0;i<arr.length;i++){
            arr[i] = sc.nextInt();
            total = total + arr[i];
        }

        if(total>max1){
            return -1;
        }

        return total;
    }
    public void getObtainedMarkks(){
        sc=new Scanner(System.in);
        System.out.println("Enter how many no. of subjects in year1 :> ");
        s1 =sc.nextInt();
        o1 = getSubjectMarks(s1);

        System.out.println("Enter how many no. of subjects in year2 :> ");
        s2 = sc.nextInt();
        o2 = getSubjectMarks(s2);

        System.out.println("Enter how many no. of subjects in year3 :> ");
        s3 = sc.nextInt();
        o3 = getSubjectMarks(s3);
        if(o1==-1 ||o2 ==-1|| o3==-1){
            System.out.println("Invalid or more marks entered byy you......");
            return;
        }
        System.out.println("Subjecty marks taken succesfully...!");
    }
    @Override
public void calculateYear1(){
        // firstYear obj = new DAOImplementation();
        p1 = (o1/max1)*100;
    }
    @Override
    public void calculateYear2(){
        // secondYear obj = new DAOImplementation();
        p2 = (o2/max2)*100;
    }
    @Override
    public void calculateYear3(){
        // thirdYear obj = new DAOImplementation();
        p3 = (o3/max3)*100;
    }
    public float showAggregate(){
     return (p1+p2+p3)/3;
    }
}
public class Assignment3 {
    public static void main(String[] args) {
        DAOImplementation obj = new DAOImplementation();
        obj.getObtainedMarkks();
        obj.calculateYear1();
        obj.calculateYear2();
        obj.calculateYear3();
        System.out.println(obj.showMsg());
        float aggr = obj.showAggregate();
        System.out.println("Overall aggregate Percentagee : "+aggr+"%");
    }
}
