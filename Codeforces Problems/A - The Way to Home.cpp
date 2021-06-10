import java.util.Scanner;
 
public class TheWaytoHome {
    static int n, d;
    static char arr[];
    static int dp[];
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        d = sc.nextInt();
        sc.nextLine();
        arr = sc.nextLine().toCharArray();
        dp = new int[n];
       
        dp[0] = 0;
        for(int i = 1;i<n;i++)
        {
            dp[i] = 1000; // max
            if(arr[i] == '0')
                continue;
            for(int j = Math.max(0,i-d) ;j<i;j++)
            {
                if(arr[i] == '1')
                    dp[i] = Math.min(dp[i],dp[j]);
            }
            dp[i]++;
        }
        System.out.println(dp[n-1] >= 1000 ? -1 : dp[n-1]);
 
 
    }
}
