//ÌâÄ¿Á´½Ó£»https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner cin = new Scanner(System.in);
        BigInteger a = cin.nextBigInteger();
        StringBuffer buf = new StringBuffer(a.toString());
        buf.reverse();
        if (a.toString().equals(buf.toString())) {
            System.out.println(a + " is a palindromic number.");
            return;
        }
        for (int i = 1; i <= 10; ++i) {
            StringBuffer tmp = new StringBuffer(a.toString());
            tmp = tmp.reverse();
            BigInteger b = new BigInteger(tmp.toString());
            BigInteger c = a.add(b);
            System.out.println(a + " + " + tmp + " = " + c);
            String s = c.toString();
            int sz = s.length();
            int flag = 1;
            for (int j = 0; j < sz; ++j)
                if (s.charAt(j) != s.charAt(sz - j - 1)) flag = 0;
            if (flag == 1) {
                System.out.println(c + " is a palindromic number.");
                return;
            }
            a = c;
        }
        System.out.println("Not found in 10 iterations.");

    }

}
