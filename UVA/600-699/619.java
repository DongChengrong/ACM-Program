import java.math.BigInteger;
import java.util.Scanner;

public class Main {


    /*
     *  UVA 619
     *  arthor : 董成荣
     *分析：简单的讲就是十进制和二进制之间的转换
     *   建立一个结构体，里面存有二十六进制和十进制的数
     *   设置一个变量MAX，表示二十六进制最长长度
     *   检测到二十六进制就转为十进制
     *   检测到十进制就转为二十六进制
     **/

    public static final int N = 11000;
    public static final BigInteger base = BigInteger.valueOf(26);

    public static void print_space(int n) {
        for (int i = 0; i < n; ++i) System.out.print(" ");
    }

    public static String toWord(BigInteger a) {
        StringBuffer s = new StringBuffer();
        while (a.compareTo(BigInteger.ZERO) != 0) {
            int tmp = a.mod(base).intValue();
            a = a.divide(base);
            if (tmp == 0) s.append('z');
            else s.append((char)(tmp - 1 + 'a'));
        }
        return s.reverse().toString();
    }

    public static BigInteger toTen(String s) {
        int n = s.length();
        char S[] = s.toCharArray();
        BigInteger a = BigInteger.ZERO;
        for (int i = 0; i < n; ++i) {
            a = a.multiply(base).add(BigInteger.valueOf(S[i] - 'a').add(BigInteger.ONE));
        }
        return a;
    }

    public static void print_BigInteger(BigInteger a) {
        String s = a.toString();
        char S[] = s.toCharArray();
        int n = s.length() % 3;
        int j = 0, f = 0;
        if (n != 0) {
            f = 1;
            for (j = 0; j < n; ++j) System.out.print(S[j]);

        }
        int cc = 0;
        n = s.length();
        while (j < n) {
            if (cc % 3 == 0 && f == 1) {
                System.out.print(',');
            }
            if (cc % 3 == 0 && f != 1) f = 1;
            cc++;
            System.out.print(S[j++]);
        }
    }

    public static void main(String[] args) {
        String s1, s2;
        BigInteger b;
        Scanner cin = new Scanner(System.in);
        int MAX = 22;
        while (cin.hasNext()) {

            s1 = cin.next();
            if (s1.compareTo("*") == 0) break;
            else if (s1.charAt(0) <= 'z' && s1.charAt(0) >= 'a') {
                System.out.print(s1);
                print_space(MAX - s1.length());
                print_BigInteger(toTen(s1));
            } else {
                b = new BigInteger(s1);
                s2 = toWord(b);
                System.out.print(s2);
                print_space(MAX - s2.length());
                print_BigInteger(b);
            }
            System.out.println("");
        }
    }

}
