import java.awt.*;
import java.io.*;
import java.util.*;
 
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
        Scanner sc = new Scanner(new File("input.txt"));
         PrintWriter out = new PrintWriter("output.txt");
 
        int n = sc.nextInt();
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
           arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int min  = Integer.MAX_VALUE;
        for (int i = 0; i <n ; i++) {
            min = Math.min(min , erased(i , arr));
          //  System.out.println(erased(i,arr));
 
        }
        out.println(min);
        out.flush();
 
 
    }
    static int erased(int i , Integer []arr)
    {
        // get lower bound
        int l = 0;
        int r = i;
        int lowerIdx = i;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid] >= arr[i])
            {
                lowerIdx  = mid;
                r = mid-1;
            }else
            {
 
                l = mid+1;
            }
        }
        int higherIdx = arr.length;
        l = i;
        r  = arr.length-1;
        while(l<=r)
        {
            int mid = l + (r - l )/2;
            if(arr[mid] > 2*arr[i])
            {
                higherIdx  = mid;
                r = mid- 1;
            }else
            {
                l = mid + 1;
            }
        }
        return ( lowerIdx + arr.length - higherIdx);
    }
}
