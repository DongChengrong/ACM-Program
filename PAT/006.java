//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4043
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        BigInteger a, b;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            System.out.println(a.divide(b) + " " + a.mod(b));
        }
    }

}
