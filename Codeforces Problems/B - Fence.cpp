import java.util.Scanner;
 
public class Fence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n + 1];
        int[] res = new int[n + 1];
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 1; i <= k; i++) {
            res[k] += arr[i];
        }
        int l = 1;
        int idx = k;
        int min = res[k];
        for (int i = k + 1; i <= n; i++) {
            res[i] = res[i - 1] - arr[l++] +arr[i];
            if (res[i] < min) {
                min = res[i];
                idx = i;
            }
        }
        System.out.println(idx - k+1);
    }
}
