import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		BigDecimal a, b;
		Scanner cin = new Scanner(System.in);
		
		while (cin.hasNext()) {
			a = cin.nextBigDecimal();
			b = cin.nextBigDecimal();
			if (a.compareTo(b) == 0) System.out.println("YES");
			else System.out.println("NO");
		}

	}

}