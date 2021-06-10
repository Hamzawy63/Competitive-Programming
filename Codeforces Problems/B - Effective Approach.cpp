 
 
import java.util.Arrays;
import java.util.Scanner;
 
public class Effective_Approach {
 
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n+1];
        Arrays.fill(arr,-1);
        for (int i = 0; i < n; i++) {
            arr[sc.nextInt()] = i;
        }
        int q = sc.nextInt();
        long res1 = 0, res2 = 0;
        while (q-- > 0) {
            int tmp = sc.nextInt();
            res1 += (arr[tmp]+1);
            res2 += (n - arr[tmp]);
        }
        System.out.println(res1+" "+res2);
 
 
    }
 
 
}
 
