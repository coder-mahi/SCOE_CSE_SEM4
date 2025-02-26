import java.math.*;
import java.util.*;
public class binomialDistribution {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("trials(n):");
        int n = sc.nextInt();
        System.out.print("no of success(k):");
        int k = sc.nextInt();
        System.out.print("probability of success(p):");
        double p = sc.nextDouble();
        double binomialProbability = findBinomialDistribution(n,k,p);
        System.out.println("Binomial Distribution Probability : "+binomialProbability);
    }

    public static double findBinomialDistribution(int n, int k, double p) 
    {
        double q= 1-p;
        return combination(n,k)*Math.pow(p,k)*Math.pow(q,n-k);
    }
    public static long combination(int n, int k) 
    {
        return fact(n)/(fact(k)*fact(n-k));
    }

    public static long fact(int num) {
        long res=1;
        for (int i=1; i<=num;i++) {
            res=res*i;
        }
        return res;
    }
}
