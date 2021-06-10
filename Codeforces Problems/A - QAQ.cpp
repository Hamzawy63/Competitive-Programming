 
 
import java.util.Scanner;
 
public class QAQ {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
        int res =0;
        for(int i = 0 ;i<s.length;i++)
        {
            for(int j = i ;j<s.length;j++)
            {
                for(int k = j ;k<s.length;k++)
                {
                    if(s[i] == 'Q' &&s[j] == 'A' &&s[k] == 'Q' )
                        res++;
                }
 
            }
        }
        System.out.println(res);
    }
}
