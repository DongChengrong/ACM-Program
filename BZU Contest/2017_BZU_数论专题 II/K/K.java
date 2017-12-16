import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int kase = 1; kase <= T; kase++)
		{
			BigInteger a,b,c;
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			c = a.divide(b);
						
			if(b.multiply(c).compareTo(a) == 0) System.out.println("Case "+kase+": divisible");
			else System.out.println("Case "+kase+": not divisible");
		}

	}

}
