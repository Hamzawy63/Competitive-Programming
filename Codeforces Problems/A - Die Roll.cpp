import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
 
public class Hamza {
    public static void main(String args[])
    {
        int m, n;
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        int k = 6-max(m,n)+1    ;
        int gcd = gcd(k,6);
            System.out.println(k/gcd +"/"+6/gcd);
 
 
    }
    public static int gcd(int num1 , int num2) {
 
 
        while (num1 != num2) {
            if(num1 > num2)
                num1 = num1 - num2;
            else
                num2 = num2 - num1;
        }
 
        return  num2;
    }
    public static int  max(int a,int b) {
        return a>b ? a: b;
    }
 
 
}
 
 
