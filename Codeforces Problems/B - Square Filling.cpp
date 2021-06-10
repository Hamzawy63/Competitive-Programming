import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Collection;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
 
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
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] arr = new int[r][c];
            int[][] arr2 = new int[r][c];
            Queue<Integer> q1 = new LinkedList<>();
            Queue<Integer> q2 = new LinkedList<>();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    arr[i][j] = in.nextInt();
                    arr2[i][j] = 0;
                }
            }
            for (int i = 0; i < r - 1; i++) {
                for (int j = 0; j < c - 1; j++) {
                    if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
                        q1.add(i + 1);
                        q2.add(j + 1);
                        arr2[i][j] = 1;
                        arr2[i][j + 1] = 1;
                        arr2[i + 1][j] = 1;
                        arr2[i + 1][j + 1] = 1;
                    }
                }
            }
 
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (arr[i][j] != arr2[i][j]) {
                        out.println(-1);
                        return;
                    }
                }
            }
            out.println(q1.size());
            while (!q1.isEmpty()) {
                out.println(q1.remove() + " " + q2.remove());
            }
 
        }
 
    }
}
 
