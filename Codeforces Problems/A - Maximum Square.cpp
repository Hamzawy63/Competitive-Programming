import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Stack;
 
public class C {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
 
    public static void main(String[] args) throws IOException {
        long arr[] = new long[11];
        for (int i = 0; i < 11; i++) {
            arr[i] = (long) Math.pow(3, i);
        }
        long subset[] = new long[1 << 10];
        for (int i = 0; i < (1<<10); i++)
        {
 
            for (int j = 0; j < 10; j++)
                if ((i & (1 << j)) > 0)
                    subset[i] +=arr[j];
        }
        int q = readInt();
        outer:
        while (q-- > 0) {
            long n = readLong();
            int l = 0;
            int r = (1<<10) -1;
            int idx = 39;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (subset[mid] > n) {
                    r = mid - 1;
                    idx = mid;
                } else if (subset[mid] == n) {
                    System.out.println(subset[mid]);
                    continue outer;
                } else {
                    l = mid + 1;
                }
 
            }
 
            System.out.println(subset[idx]);
        }
 
 
    }
 
    static long readLong() throws IOException {
 
        return Long.parseLong(sc.readLine());
    }
 
    static int readInt() throws IOException {
 
        return Integer.parseInt(sc.readLine());
    }
 
    static String readLine() throws IOException {
        return sc.readLine();
    }
 
    static int[] readArray(int n) throws IOException {
        String[] s = sc.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }
        return arr;
    }
 
 
}
