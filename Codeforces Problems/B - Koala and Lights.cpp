import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
 
        int[] arr = new int[1000];
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int j = 0;
            int k = 0;
            int add = Character.getNumericValue(s.charAt(i));
            while (j<1000)
            {
                for (;j<b+a*k && j<1000;j++)
                {
                    arr[j]+=add;
                    if(arr[j] > res)
                        res = arr[j];
                }
                add = -1 * add + 1;
                k++;
            }
 
 
 
        }
 
        System.out.println(res);
 
    }
}
