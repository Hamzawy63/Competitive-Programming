import java.awt.*;
import java.io.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;
 
public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    static FastReader sc = new FastReader();
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
 
    public static void main(String[] args) throws IOException {
        int q = sc.nextInt();
        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
 
            int min = Math.min(Math.min(a, b), c);
            a-= min;
            b-= min;
            c-= min;
 
            if (a != 0 && b != 0) {
                int increase  = Math.min(a,b);
                min += Math.min(increase , (a + b) / 3);
            }
            System.out.println(min);
        }
    }
}
