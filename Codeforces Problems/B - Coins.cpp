 
import java.util.Arrays;
import java.util.Scanner;
 
public class Coins {
    static byte a = 0;
    static byte b = 0;
    static byte c = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i = 0 ;i<3 ;i++)
        {
            String tmp = sc.nextLine();
            if(tmp.charAt(1) == '>' )
                 increase(tmp.charAt(0));
            else
                increase(tmp.charAt(2));
        }
        byte []arr = {a,b,c};
        Arrays.sort(arr);
        if(arr[0] == arr[1] || arr[1] == arr[2])
        {
            System.out.println("Impossible");
            return;
        }
        for(int i = 0 ;i<=2 ;i++)
        {
            if(a == arr[i])
                System.out.print('A');
            else if(b == arr[i])
                System.out.print('B');
            else if(c == arr[i])
                System.out.print('C');
        }
    }
    public static void increase(char  x)
    {
        switch (x)
        {
            case 'A':
                a++;
                break;
            case 'B':
               b++;
                break;
            case 'C':
               c++;
 
        }
    }
}
 
 
