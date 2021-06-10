import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
public class Main {
    static long MOD = (long) 1e9 + 7;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
 
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 1; i <n ; i++) {
            a[i] = Math.max(a[i-1] , a[i]  + b[i-1]);
            b[i] = Math.max(b[i-1] , b[i]  + a[i-1]);
        }
        System.out.println(Math.max(a[n-1] , b[n-1]));
    }
}
