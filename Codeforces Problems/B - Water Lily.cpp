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
            int h = in.nextInt();
            int l = in.nextInt();
            double theta = Math.atan((double) l / (double) h);
            //System.out.println(theta);
            double alpha = Math.PI / 2.0 - theta;
            out.println(l * Math.tan(theta - alpha));
        }
 
    }
}
 
