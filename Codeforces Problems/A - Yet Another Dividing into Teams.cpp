import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
 
public class Main {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
 
    public static void main(String[] args) throws IOException {
        int q = readInt();
        while (q-- > 0) {
            int n = readInt();
            int res = 1;
            int[] arr = readArray(n);
            outer:
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (Math.abs(arr[i] - arr[j]) == 1) {
                        res = 2;
                        break outer;
                    }
                }
            }
            System.out.println(res);
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
