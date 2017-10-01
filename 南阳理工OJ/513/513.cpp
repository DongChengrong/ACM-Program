 
import java.io.BufferedInputStream;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigDecimal a,b;
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while(cin.hasNext())
		{
			a = cin.nextBigDecimal();
			b = cin.nextBigDecimal();
			BigDecimal c = a.add(b);
			if(c.compareTo(BigDecimal.valueOf(0)) == 0) System.out.println("0");
			else System.out.println(c.stripTrailingZeros().toPlainString());
		}

	}

}        
