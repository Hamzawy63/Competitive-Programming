import java.math.BigInteger;
import java.util.Scanner;
 
public class Counterexample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
 
         BigInteger l,r;
        l = sc.nextBigInteger();
        r = sc.nextBigInteger();
      //  System.out.println(l.gcd(r));//.equals(1));
        for(BigInteger i = l ;i.compareTo(r) != 1 ;i= i.add(new BigInteger("1")))
        {
            for(BigInteger j = i ;j.compareTo(r) != 1 ;j=j.add(new BigInteger("1")))
            {
                for(BigInteger k = j ;k.compareTo(r) != 1 ;k=k.add(new BigInteger("1")))
                {
                    BigInteger tmp = new BigInteger("1");
                    if(i.gcd(j).equals(tmp)  &&   j.gcd(k).equals(tmp)&& !(i.gcd(k).equals(tmp)))
                    {
                        System.out.println(i+" "+j+" "+k);
                        return;
                    }
                }
 
            }
 
        }
        System.out.println(-1);
 
 
 
    }
}
