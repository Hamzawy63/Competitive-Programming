import java.util.*;
import java.io.*;
 
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
        int m = sc.nextInt();
        boolean[] arr = new boolean[10005];
        arr[n] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        int level = -1;
        outer:
        while (!q.isEmpty()) {
            int size = q.size();
            level++;
            while (size-- > 0) {
                int t = q.remove();
                if (t == m)
                    break outer;
                if ( 2*t < 10005 && t > 0 &&  arr[2 * t] == false  ) {
                    arr[2 * t] = true;
                    q.add(2 * t);
                }
                if (arr[t - 1] == false && t - 1 > 0) {
                    arr[t - 1] = true;
                    q.add(t - 1);
                }
 
            }
 
        }
        System.out.println(level);
    }
 
 
}
