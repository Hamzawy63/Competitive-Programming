import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
public class FindTheBone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> holes = new ArrayList<Integer>(m);
        for(int i = 0;i<m;i++)
        {
            holes.add(sc.nextInt());
        }
        Collections.sort(holes);
        int pos = 1;
        boolean fall = holes.get(0)== 1 ? true: false;
        for(int i = 0 ;i<k && !fall;i++)
        {
            int x1 = sc.nextInt();
            int x2 = sc.nextInt();
            if(pos == x1 || pos == x2)
            {
                pos = pos == x1 ? x2 : x1;
                if(Collections.binarySearch(holes , pos) >= 0)
                    fall = true;
             }
        }
 
        System.out.println(pos);
    }
}
