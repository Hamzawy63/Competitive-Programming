import java.util.Scanner;
 
public class Kefa_and_First_Steps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        int max = 0, res = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1])
                res++;
            else {
                max = Math.max(res , max );
                res = 1;






