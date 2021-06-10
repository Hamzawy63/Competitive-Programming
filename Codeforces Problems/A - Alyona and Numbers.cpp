import java.util.Scanner;
 
public class Alyona_and_Numbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long m = sc.nextInt();
        long res = 0;
        for(int i=1;i<=n;i++){
            res+=(m+i)/5-i/5;
        }
        System.out.println(res);
 
    }
}
