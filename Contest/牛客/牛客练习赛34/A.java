import java.math.BigInteger;
import java.util.Scanner;
 
 
public class Main {
 
    public static void main(String[] args) {
        // TODO Auto-generated method stub
 
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- > 0) {
            BigInteger a = cin.nextBigInteger();
            a = a.divide(BigInteger.valueOf(2));
            System.out.println(a.multiply(BigInteger.valueOf(2)));
        }
 
 
    }
 
}