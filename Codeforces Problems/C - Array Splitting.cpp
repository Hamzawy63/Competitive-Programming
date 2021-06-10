import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            long arr[] = new long[n];
            long magic[] = new long[n - 1];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextLong();
            }
            for (int i = 0, j = 0; i < n - 1; i++) {
                magic[j++] = arr[i + 1] - arr[i];
            }
            Arrays.sort(magic);
            long res = 0;
            for (int j = 0; j < n - k; j++) {
                res += magic[j];
            }
            out.println(res);
        }
 
    }
}
 
