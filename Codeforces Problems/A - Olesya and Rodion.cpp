import java.util.Scanner;
 
public class Case_of_the_Zeros_and_Ones {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String l = sc.next();
        int  n2 = 2*(n - l.replaceAll("0" , "").length()) ;
        if(n2 > n )
        {
            System.out.println(n- (2*(n - l.replaceAll("1" , "").length())));
        }else
        {
            System.out.println(n-n2);
        }
    }
}
