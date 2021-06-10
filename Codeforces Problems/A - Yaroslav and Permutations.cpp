import java.util.Scanner;
 
public class Yaroslav_and_Permutations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[1001];
        int n = sc.nextInt();
        for(int i = 0 ;i<n ;i++ )
        {
            arr[sc.nextInt()] ++;
        }
 
        for(int i = 0 ;i<1001 ;i++)
        {
            if( arr[i] >= ((int)(Math.ceil(n/2.0)+1)))
            {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
 
 
    }
}
