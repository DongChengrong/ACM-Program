import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int T;
        BigInteger f[] = new BigInteger[100];
        f[1] = BigInteger.valueOf(1);
        for (int i = 2; i <= 55; ++i) f[i] = f[i - 1].multiply(BigInteger.valueOf(i));
        for (int i = 2; i <= 55; ++i) f[i] = f[i - 1].add(f[i]);
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int s = cin.nextInt();
            System.out.println(f[s]);
        }
    }
}