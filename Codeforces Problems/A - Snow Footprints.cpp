import java.util.Scanner;
 
public class Snow_Footprints {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int st = 0, en=0 ;
        String s = sc.nextLine();
        if(s.indexOf('R') == -1)
        {
             st= s.indexOf('L');
             en = s.lastIndexOf('L');
            System.out.println((en+1)+" "+(st));
            return;
 
        }else
        {
             st= s.indexOf('R');
             en = s.lastIndexOf('R');
        }
        if(s.indexOf('L') == -1)
          System.out.println((st+1)+" "+(en+2));
        else
            System.out.println((st+1)+" "+(en+1));
 
    }
}
