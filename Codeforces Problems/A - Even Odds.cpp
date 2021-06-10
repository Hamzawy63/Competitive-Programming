import java.util.Scanner;
 
public class EvenOdds {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        if(k == n)
        {
            if(k == 1)
                System.out.println(1);
            else
                System.out.println((n%2 == 0 )? (n) : n-1 );
            return;
        }
 
        long odds = (long )Math.ceil( n/2.0);
 
        long index = k - odds; // in case of
        System.out.println( k<=odds ? (2*k -1):(2*index));
    }
}
