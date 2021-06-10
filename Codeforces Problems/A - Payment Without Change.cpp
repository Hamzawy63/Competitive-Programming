import java.util.Scanner;
 
public class A {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            long a = sc.nextInt();
            long b = sc.nextInt();
            long n = sc.nextInt();
            long s = sc.nextInt();
            long sum = Math.min(s / n, a) * n;
            if (s - sum <= b) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
