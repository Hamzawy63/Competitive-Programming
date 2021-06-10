import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.security.Key;
import java.util.HashSet;
import java.util.Scanner;
import java.util.*;
import java.lang.Object;
 
public class Sereja_and_Array {
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        long carry = 0; /// stores the increase or decrease of each element after each operation
        for (int i = 0; i < m; i++) {
            int o = sc.nextInt();
            int index = sc.nextInt(); // bad name and not expressive
            switch (o) {
                case 1:
                    arr[index - 1] = sc.nextInt()-carry;
                    break;
                case 2:
                    carry += index;
                    break;
                case 3:
                    long minus = 0;
                    System.out.println(arr[index - 1] + carry);
                    break;
 
            }
        }
 
    }
}
