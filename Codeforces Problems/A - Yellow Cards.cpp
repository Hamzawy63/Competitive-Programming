import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
 
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a1 = sc.nextInt();
        int a2 = sc.nextInt();
        int k1 = sc.nextInt();
        int k2 = sc.nextInt();
        int n = sc.nextInt();
 
        int max = 0;
        if (k1 < k2) {
            if (n < a1 * k1)
                max = n / k1;
            else
                max += a1 + (n - k1 * a1) / k2;
        } else {
            if (n < a2 * k2)
                max = n / k2;
            else
                max += a2 + (n - k2 * a2) / k1;
        }
        int min = Math.max(0, n - (a1 * (k1 - 1) + a2 * (k2 - 1)));
 
 
        System.out.println(min + " " + max);
 
 
    }
 
 
}
