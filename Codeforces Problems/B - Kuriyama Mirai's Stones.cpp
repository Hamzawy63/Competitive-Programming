import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Kuriyama_Mirais_Stones {
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
 
 
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        Long arr[] = new Long[n];
        Long sorted[] = new Long[n];
        for (int i = 0; i < n; i++) {
            long in = sc.nextLong();
            arr[i] = in;
            sorted[i] = in;
        }
        Arrays.sort(sorted);
 
        // GET THE PREFIX SUM
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
            sorted[i] += sorted[i - 1];
        }
 
 
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int type = sc.nextInt();
            int l = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;
            // do the operation for all the user input
 
            if (type == 1) {
                if (l ==  0 )
                    System.out.println(arr[r]);
                else
                    System.out.println(arr[r] - arr[Math.max(0, l - 1)]);
 
            } else {
                if ( l == 0 )
                    System.out.println(sorted[r]);
                else
                    System.out.println(sorted[r] - sorted[Math.max(0, l - 1)]);
            }
        }
 
    }
 
}
