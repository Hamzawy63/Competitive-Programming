import java.util.Scanner;
 
public class Sasha_and_His_Trip {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() - 1;
        int v = sc.nextInt();
        int a = n - v;
        if (v >= n)
            System.out.println(n);
        else
            System.out.println(v + (a + 2) * (a + 1) / 2 - 1);
 
 
    }
}
