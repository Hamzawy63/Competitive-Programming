import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
 
        int j= 0;
        while(k>0 && j<n)
        {
            if(arr[j] < 0)
            {
                arr[j] = -1*arr[j];
                j++;k--;
            }else
            {
               break;
            }
        }
        int res = 0;
        Arrays.sort(arr);
        if(k%2 == 1)
            arr[0]*=-1;
        for (int i = 0; i <n ; i++) {
            res+=arr[i];
        }
 
        System.out.println(res);
 
 
    }
 
 
}
