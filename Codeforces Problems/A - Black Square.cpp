import java.util.Scanner;
 
public class M {
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        int []arr = new int[4];
 
        for(int i = 0 ; i<4 ; i++)
        {
            arr[i] = sc.nextInt();
 
        }
       // Scanner scc = new Scanner(System.in);
        String m = sc.nextLine();
        String s = sc.nextLine();
        int sum = 0;
        for(int i = 0 ;i<s.length() ;i++)
        {
            int n = Character.getNumericValue(s.charAt(i));
            sum += arr[n- 1];
        }
        System.out.println(sum);
    }
}
