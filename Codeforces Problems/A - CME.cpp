import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
 
public class Main {
    static long MOD = (long) 1e9 + 7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            int n = sc.nextInt();
            if (n == 2)
                System.out.println(2);
            else if (n % 2 == 0)
                System.out.println(0);
            else {
                System.out.println(1);
 
            }
        }
 
    }
}
