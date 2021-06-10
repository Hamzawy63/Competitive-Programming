import java.util.Arrays;
import java.util.Scanner;
 
public class Make_Product_Equal_One {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long negative = 0;
        long zeros = 0;
        long res = 0;
       for(int i = 0;i<n;i++)
       {
          int tmp = sc.nextInt();
          if(tmp<0)
          {
              negative++;
              res+= Math.abs(tmp) - 1;
          }else if(tmp == 0)
          {
              zeros++;
              res+=1;
 
          }else
          {
              res+=(tmp - 1);
          }
       }
       if((negative+zeros) % 2 == 1)
       {
           if(zeros==0)
           {
               res+=2;
           }
       }
 
        System.out.println(res);
 
    }
}
