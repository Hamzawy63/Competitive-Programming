import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;
 
public class Twins
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum=0,a=0,b=0;
        int []arr = new int[n];
        for(int i = 0 ;i<n ;i++)
        {
            arr[i] = sc.nextInt();
            sum+=arr[i];
        }
        b = sum;
        Arrays.sort(arr);
        reverse(arr);
        int i=0,count = 0;
        while(a<=b)
        {
            a+=arr[i];
            b-=arr[i++];
            count++;
        }
        System.out.println(count);
 
 
 
    }
 
    public static void reverse(int[] arr)
    {
        for(int i = 0,j = (arr.length-1) ;i<j ;i++,j--)
        {
            int tmp = arr[i];
            arr[i]   = arr[j];
            arr[j]   = tmp;
        }
    }
}
