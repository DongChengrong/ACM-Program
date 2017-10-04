 
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int i = 1; i <= T; i++)
		{
			BigInteger a,b;
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			System.out.println("Case "+i+":");
			System.out.println(a+" + "+b+" = "+a.add(b));
		}

	}

}
        
