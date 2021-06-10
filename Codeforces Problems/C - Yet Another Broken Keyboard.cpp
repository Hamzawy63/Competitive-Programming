import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            int n = sc.nextInt();
            int res =0;
            String test;
            for (int i = 1; i <= 9; i++) {
                test = "";
                for (int j = 1; j <= 9; j++) {
                   test += i;
                    if(Long.parseLong(test) <= n)
                        res ++;
                }
            }
            System.out.println(res);





