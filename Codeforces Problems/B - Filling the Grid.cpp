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
    static final double E = 0.000000001;
    static final long MOD = (long) (1e9 + 7);
    static final long MAX = (long) 1e9;
 
    public static void main(String[] args) throws IOException {
      int h = sc.nextInt();
      int w = sc.nextInt();
      int[][]arr  = new int[h+1][w+1];
        for (int i = 1; i <=h ; i++) {
            arr[i][0] = sc.nextInt();
        }
 
        for (int i = 1; i <=w ; i++) {
            arr[0][i] = sc.nextInt();
        }
        long res = 1;
        for (int i = 1; i <arr.length ; i++) {
            for (int j = 1; j <arr[0].length ; j++) {
                if((j - arr[i][0] <= 0 && i - arr[0][j] == 1 )||(j - arr[i][0] == 1 && i - arr[0][j] <= 0 ))
                {
                    System.out.println(0);
                    return;
                }
                if(!(j - arr[i][0] <=1 || i - arr[0][j] <=1))
                {
 
                    //System.out.printf(" %d and %d",i,j);
                    if(res == 0) res = 1;
                    res = (res*2 )%MOD;
                }
 
            }
        }
        System.out.println(res);
 
    }
 
    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
 
    }
 
 
}
