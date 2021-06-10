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
        int a = sc.nextInt();
        int b = sc.nextInt();
        outer:for(int i = a ; i<=b;i++)
        {
            int tmp = i;
            int[]arr  = new int[10];
            while(tmp!=0)
            {
                arr[tmp%10]++;
                tmp/=10;
            }
            for (int j = 0; j <10 ; j++) {
                if(arr[j] > 1)
                    continue outer;
            }
            System.out.println(i);
            return;
 
        }
        System.out.println(-1);
    }
 
    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
 
    }
 
 
}
