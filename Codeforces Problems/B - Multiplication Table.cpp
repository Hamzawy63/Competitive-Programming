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
  //  static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) {
 
        int n = sc.nextInt()+1;
        long[][]arr=  new long[n][n];
        for (int i = 1; i <n ; i++) {
            for (int j = 1; j <n ; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        long a1 =(long) Math.sqrt(arr[1][2] * arr[1][3] / arr[3][2]);
        System.out.print(a1 + " ");
        for (int i = 2; i <n ; i++) {
            System.out.print(arr[1][i] / a1 +" ");
        }
 
    }
 
 
}
