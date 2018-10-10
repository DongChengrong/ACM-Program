import org.omg.Messaging.SYNC_WITH_TRANSPORT;
import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {


    public static BigInteger f[] = new BigInteger[100000];
    public static long base = 1;
    public static long maxInteger = 1073741824l;

    public static void init() {
        int cnt = 2;
        f[0] = BigInteger.valueOf(4);
        f[1] = BigInteger.valueOf(14);
        for (int i = 2; i <= 60; ++i) f[i] = f[i - 1].multiply(BigInteger.valueOf(4)).subtract(f[i - 2]);
        //while ((f[cnt] = f[cnt - 1].multiply(BigInteger.valueOf(4)).subtract(f[cnt - 2])).compareTo(BigInteger.valueOf(base << 33)) < 0 ) ++cnt;
        //System.out.println(cnt);
    }

    public static BigInteger lower_bound(BigInteger a) {
        for (int i = 0; i <= 60; ++i) if (f[i].compareTo(a) >= 0) return f[i];
        return BigInteger.valueOf(-1);
    }

    public static void main(String[] args) {
        init();
        System.out.println(f[50]);
        //for (int i = 0; i <= 17; ++i) System.out.println(f[i]);
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T > 0) {
            --T;
            BigInteger a = cin.nextBigInteger();
            BigInteger res = lower_bound(a);
            System.out.println(res);
        }
    }

}
