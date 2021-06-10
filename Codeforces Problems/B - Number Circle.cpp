import java.util.Scanner;
 
public class Bear_and_Finding_Criminals {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int []arr = new int[n];
 
        for (int i = 0 ;i<n ;i++)
            arr[i] = sc.nextInt();
 
 
        int count = ( arr[k-1] == 1) ? 1 : 0;
        for(int i=1  ;i<=Math.max(k,n-k)   ;i++)

























