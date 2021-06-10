import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                String x = in.nextLine();
                String y = in.nextLine();
                int lsb = 0;
                for (int j = y.length() - 1; j >= 0; j--) {
                    if (y.charAt(j) == '0')
                        lsb++;
                    else
                        break;
                }
                int res = 0;
                for (int j = x.length() - lsb - 1; j > 0; j--) {
                    if (x.charAt(j) == '0')
                        res++;
                    else
                        break;
                }
                out.println(res);
            }
        }
 
    }
}
 
