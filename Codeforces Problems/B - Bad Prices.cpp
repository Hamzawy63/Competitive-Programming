import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;
 
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
            int q = in.nextInt();
            while (q-- > 0) {
                long n = in.nextLong();
                long k = in.nextLong();
                ArrayList<Long> arr = new ArrayList<Long>();
                arr.add(k % 10);
                long K = k * 2;
                long sum = arr.get(0);
                while (K % 10 != arr.get(0)) {
                    arr.add(K % 10);
                    sum += K % 10;
                    K += k;
                }
                long res = ((n / k) / arr.size()) * sum;
                for (int i = 0; i < ((n / k) % arr.size()); i++) {
                    res += arr.get(i);
                }
                out.println(res);
 
 
            }
        }
 
    }
}
 
