import java.awt.*;
import java.util.*;
import java.io.*;
 
 
public class mainn {
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
    static int MAX;
    static double E = 0.000000001;
 
    public static void main(String[] args) throws IOException {
 
        int n = sc.nextInt();
        point[]arr = new point[n];
        for (int i = 0; i <n ; i++) {
            arr[i] = new point(sc.nextInt() , i);
        }
        int res= 0;
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            res += arr[i].x*i + 1;
        }
        System.out.println(res);
        for (int i = 0; i < n ; i++) {
            System.out.print(arr[i].y + 1 + " ");
        }
 
 
    }
   static class point implements Comparable<point>
   {
       int x,y;
       public point(int x, int y)
       {
           this.x = x;
           this.y = y;
       }
       @Override
       public int compareTo(point o)
       {
           return o.x - this.x;
       }
   }
 
}
