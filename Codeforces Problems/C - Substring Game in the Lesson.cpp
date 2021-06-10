import java.io.*;
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
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = sc.nextLine();
        bw.write("Mike\n");
        char min = s.charAt(0);
        int len = s.length();
        for (int i = 1; i < len; i++) {
            boolean flag = true;
 
            if (s.charAt(i) <= min) {
                flag = false;
                min = s.charAt(i);
            }
            if (flag)
              bw.write("Ann\n");
            else
                bw.write("Mike\n");
 
        }
        bw.flush();
 
 
 
    }
 
 
}
