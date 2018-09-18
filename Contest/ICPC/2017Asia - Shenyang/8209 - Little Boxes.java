import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int T;
        BigInteger a, b, c, d;
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while (T > 0) {
            T--;
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            c = cin.nextBigInteger();
            d = cin.nextBigInteger();
            System.out.println(a.add(b.add(c.add(d))));
        }
    }
}
