import java.util.Scanner;
 
public class Theatre_Square {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long m = sc.nextInt();
        long a = sc.nextInt();
        double x = Math.ceil(n / (double)a);
        double y = Math.ceil(m / (double)a);
        System.out.println((long)(x*y));
 
    }
}
