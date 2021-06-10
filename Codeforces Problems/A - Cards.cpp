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
 
        int k = sc.nextInt();
        int z=0,n=0;
        String s = sc.nextLine();
        int len = s.length();
        for(int i = 0;i<len;i++)
        {
            if(s.charAt(i) == 'z')
                z++;
            else if(s.charAt(i) == 'n')
                n++;
        }
       while(n--  > 0)
       {
           System.out.print(1+" ");
       }
       while (z-- > 0)
           System.out.println(0+" ");
 
 
    }
 
 
}
