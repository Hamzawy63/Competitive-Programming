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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            boolean status = true;
            boolean res = true;
            long peek = 0;
            for (int i = 0; i < n; i++) {
                long tmp = in.nextLong();
                if (status == true) {
                    if (tmp > peek) {
                        peek = tmp;
                    } else {
                        peek = tmp;
                        status = false;
                    }
                } else {
                    if (tmp < peek) {
                        peek = tmp;
                    } else {
                        res = false;
                    }
                }
            }
            out.println(res ? "YES" : "NO");
 
        }
 
    }
}
 
