import java.util.Scanner;
 
public class Maximum_Increase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int max = 1;
        int i = 1;
        while (i < n) {
            int j = i;
            int tmp = 1;
            while (j < n) {
                if (arr[j] > arr[j - 1]) {
                    tmp++;
                    j++;
                } else
                    break;
            }
            max = Math.max(max, tmp);
            i = ++j;
 
        }
        System.out.println(max);
    }
}
