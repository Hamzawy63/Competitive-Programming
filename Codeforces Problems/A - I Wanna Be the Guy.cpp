import java.util.HashSet;
import java.util.Scanner;
 
public class I_Wanna_Be_the_Guy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<Integer> arr = new HashSet<Integer>();
        int n = sc.nextInt();
        for(int i = 0 ;i<2 ;i++)
        {
            int k = sc.nextInt();
            for(int j = 0 ;j<k ;j++)
            {
                arr.add(sc.nextInt());
            }
        }
        if(arr.size() == n)
        {
            System.out.println("I become the guy.");
        }else
        {
            System.out.println("Oh, my keyboard!");
        }
    }
}
