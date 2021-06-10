import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Hamza Hassan
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long n = in.nextInt();
            long a = in.nextInt();
            long b = in.nextInt();
            long p = in.nextInt();
            long q = in.nextInt();
 
            long common = n / lcm(a, b);
            long res = common * Math.max(p, q) + (n / a - common) * p + (n / b - common) * q;
            out.println(res);
 
        }
 
        static long gcd(long a, long b) {
            if (a == 0) {
                return b;
            } else {
                return gcd(b % a, a);
 
            }
        }
 
        static long lcm(long a, long b) {
            return a * b / gcd(a, b);
        }
 
    }
}
 
