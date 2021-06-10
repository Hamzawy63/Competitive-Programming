import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
 
public class monMain {
 
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfGroups = 0 ;
        int position = 0;
       int  n = sc.nextInt();
      for(int i = 0 ;i<n ;i++)
      {
          int tmp = sc.nextInt();
          if((tmp) != position)
          {
              numberOfGroups++;
              position =  tmp;
          }
      }
        System.out.println(numberOfGroups);
 
 
 
    }
 
}
