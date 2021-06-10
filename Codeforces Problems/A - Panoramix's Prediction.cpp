import java.util.Scanner;
 
public class Panoramixs_Prediction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean prime = true;
        boolean[] primes = new boolean[51];
        primes[0] = false;
        primes[1] = false;
        primes[2] = true;
        for (int i = 2; i < 51; i++) {
            primes[i] = true;
        }
        for (int i = 2; i < 51; i++) {
            // if prime then it is true
            for (int j = 2; j < i; j++) {
                if (i % j == 0)
                    primes[i] = false;
            }
        }
        for (int i = n + 1; i < m; i++) {
            if (primes[i] == true) {
                System.out.println("NO");
                return;
            }
        }
        // it is guaranteed that n!=m
        if (primes[m] == false) {
            System.out.println("NO");
        } else
            System.out.println("YES");
 
 
    }
}
