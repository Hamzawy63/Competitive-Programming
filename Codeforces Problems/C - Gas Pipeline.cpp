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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
 
            int q = in.nextInt();
            while (q-- > 0) {
                int n = in.nextInt();
                long a = in.nextLong();
                long b = in.nextLong();
                in.nextLine();
                String s = in.nextLine();
                long dp[][] = new long[n + 1][2];
                for (int i = 0; i < dp.length; i++) {
                    for (int j = 0; j < dp[0].length; j++) {
                        dp[i][j] = (long) 1e15;
                    }
                }
                dp[0][0] = b;
                // [i][0] --->>> height 1
                // [i][1] --->>> height 2
                for (int i = 0; i < s.length() - 1; i++) {
                    if (s.charAt(i + 1) == '1' || s.charAt(i) == '1') {
                        dp[i + 1][1] = Math.min(dp[i][0] + 2 * a + 2 * b, dp[i][1] + a + 2 * b);
 
                    } else {
                        dp[i + 1][1] = Math.min(dp[i][0] + 2 * a + 2 * b, dp[i][1] + a + 2 * b);
                        dp[i + 1][0] = Math.min(dp[i][0] + a + b, dp[i][1] + 2 * a + b);
                    }
                }
                long res = Math.min(dp[n - 1][0] + a + b, dp[n - 1][1] + 2 * a + b);
                out.println(res);
            }
        }
 
    }
}
 
