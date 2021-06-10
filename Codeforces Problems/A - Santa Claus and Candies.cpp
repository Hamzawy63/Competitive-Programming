import java.util.Scanner;
 
public class Santa_Claus_And_Candies {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[101];
        for (int i = 1; i < 100; i++) {
            arr[i] = i * (i + 1) / 2;
        }
        int n = sc.nextInt();
 
        int l = 1;
        int r = arr.length - 1;
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= n) {
                idx = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        System.out.println(idx);
        for(int i = 1 ;i<idx;i++)
            System.out.print(i+" ");
 
        System.out.println(n- idx*(idx-1)/2);
 
 
    }
}
