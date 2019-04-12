import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger a, b; String s;
		while (in.hasNext()) {
			a = in.nextBigInteger();
			s = in.next();
			b = in.nextBigInteger();
			if (s.equals("%")) System.out.println(a.mod(b));
			else System.out.println(a.divide(b));
		}

	}

}
