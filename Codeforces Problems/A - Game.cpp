import java.util.Scanner;
import java.util.Arrays; 
public class main
{
    public static void main(String []args )
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []arr = new int[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
         Arrays.sort(arr);
         int x = (n%2 == 0) ? n/2-1 :n/2;
         System.out.println(arr[x]);
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
