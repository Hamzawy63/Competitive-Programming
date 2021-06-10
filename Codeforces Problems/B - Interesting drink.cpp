import java.util.Scanner;
 
public class Sereja_and_Suffixes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[]freq = new int[100001];
        int[]arr  = new int[100001];
 
        for(int i = 0 ;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        int res = 0;
        for (int i = n-1; i >=0 ; i--) {
















