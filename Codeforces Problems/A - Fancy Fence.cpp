import java.util.Scanner;
 
public class Fancy_Fence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n-- >0)
        {
            int a = sc.nextInt();
            System.out.println(a>=60 && 360%(180 - a) == 0 ?"YES":"NO" );
        }
    }
}
