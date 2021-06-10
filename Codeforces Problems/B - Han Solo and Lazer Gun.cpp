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
 
    public static void main(String[] args) throws IOException {
        int n = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int v = 0,h = 0;
        HashSet<Double> hs = new HashSet<Double>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
 
            if (a == x) {
                v = 1;
            }else if(b == y){
                h = 1;
            } else {
                double slope = ((b - y) / (double) (a - x));
                slope = Double.parseDouble(String.format("%.10f", slope));
                hs.add(slope);
            }
        }
        System.out.println(hs.size() + v+h);
 
    }
 
 
}
