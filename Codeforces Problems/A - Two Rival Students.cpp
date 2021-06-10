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
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
 
    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int x = in.nextInt();
            int f = in.nextInt();
            int s = in.nextInt();
 
            int a = Math.min(f, s);
            int b = Math.max(f, s);
            a = a - Math.min(x, a - 1);
            x -= (Math.min(f, s) - a);
            b += Math.min(n - b, x);
//       out.println(b - a );
//
//        while (x > 0) {
//            if (x > 0 && a > 1) {
//                a--;
//                x--;
//            }
//            else if (x > 0 && b < n) {
//                b++;
//                x--;
//            }else
//                break;
//        }
            out.println(b - a);
//
 
        }
 
    }
}
 
