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
            int x = in.nextInt();
            int y = in.nextInt();
            long min_number = 2000000000;
            int min_inedex = 0;
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextLong();
                if (arr[i] < min_number) {
                    min_number = arr[i];
                    min_inedex = i;
                }
            }
            for (int i = 0; i < n; i++) {
 
                long min = 2000000000;
                for (int j = (i - x); j <= (i + y); j++) {
                    if (j > arr.length - 1 || j < 0)
                        continue;
                    if (arr[j] < min)
                        min = arr[j];
 
                }
                if (min == arr[i]) {
                    out.println(i + 1);
                    return;
                }
 
            }
            out.println(min_inedex + 1);
 
        }
 
    }
}
 
