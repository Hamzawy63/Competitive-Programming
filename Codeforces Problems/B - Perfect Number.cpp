import java.util.Scanner;
 
public class Perfect_Number {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int i;
        for ( i = 1; a != 0; i++) {
            int t = i;
            int sod = 0;
            while (t != 0) {
                sod += t % 10;
                t = t/10;
            }
            if(sod == 10)
                a--;
        }
        System.out.println(i-1);
    }
}
