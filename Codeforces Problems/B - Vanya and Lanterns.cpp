//package Div2_B;
 
import java.util.Arrays;
import java.util.Scanner;
 
public class Vanya_and_Lanterns {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long []arr = new long [n];
        long L  = sc.nextLong();
        for(int i = 0 ;i<n ;i++)
        {
            arr[i] = sc.nextLong();
        }
        Arrays.sort(arr);
        long max = 2 *  Math.max(L - arr[n-1] , arr[0]);
        for(int  i = 1 ;i<n ;i++)
        {
            max = Math.max(arr[i] - arr[i-1] , max);
        }
        System.out.println(max/2.0);
    }
}
