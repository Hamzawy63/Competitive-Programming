 
 
import java.util.Arrays;
import java.util.Scanner;
 
public class Devu_the_Dumb_Guy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long) arr[i] * x;
            x = Math.max(x - 1, 1);
        }
        System.out.println(res);
    }
 
}
