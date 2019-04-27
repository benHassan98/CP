import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		
		Scanner Input=new Scanner(System.in);
		long n=Input.nextLong(),m=Input.nextLong(),k=Input.nextLong();		
		long x=(n/k)*(k-1)+(n%k);		
		if(m<=x)System.out.println(m);
		else{
		BigInteger MOD=BigInteger.valueOf(1000000009);
		BigInteger X=BigInteger.valueOf(x);	
		BigInteger K=BigInteger.valueOf(k);
		BigInteger extra=BigInteger.valueOf(m-x);	
		X=X.subtract( extra.multiply(K.subtract(BigInteger.valueOf(1)))  );
		BigInteger Ans=BigInteger.valueOf(2);
		Ans=Ans.modPow(extra.add(BigInteger.valueOf(1)), MOD);
		Ans=Ans.subtract(BigInteger.valueOf(2));
		Ans=(Ans.multiply(K.mod(MOD)).mod(MOD));
		Ans=((Ans.mod(MOD)).add(X)).mod(MOD);
		System.out.println(Ans);
		}
				
		Input.close();		
		
	}

}
