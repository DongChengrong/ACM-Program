import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    static final int N = 1100;

    static BigInteger f[] = new BigInteger[N];

    static void init() {
        f[1] = BigInteger.valueOf(0);
        f[2] = f[3] = BigInteger.valueOf(1);
        for (int i = 4; i <= 1000; ++i) f[i] = f[i - 1].add(f[i - 2].multiply(BigInteger.valueOf(2)));
    }

    public static void main(String[] args) {
        init();
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            System.out.println(f[n]);
        }
    }

}
