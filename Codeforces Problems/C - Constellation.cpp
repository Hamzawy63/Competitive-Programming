import java.util.Arrays;
import java.util.Scanner;
public class Constellation  {
    static final double E = 0.0000001;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        star []arr = new star[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = new star(sc.nextLong() , sc.nextLong(),i+1);
        }
        Arrays.sort(arr);
        System.out.print(arr[0].index+" "+arr[1].index);
        for(int i = 2 ;i<arr.length;i++)
        {
            if(areTheySameLine(arr[0],arr[1],arr[i]) == false)
            {
                System.out.println(" "+arr[i].index);
                break;
            }
        }
    }
    static class star implements Comparable<star>
    {
        long x;
        long y;
        int index ;
        star(long a , long b,int index)
        {
            this.x = a;
            this.y = b;
            this.index = index;
        }
        @Override
        public int compareTo(star another)
        {
            if (Long.compare(this.x,another.x )==0)
            {
                return Long.compare(this.y,another.y);
            }else
            {
                return Long.compare(this.x,another.x );
            }
        }
 
 
 
    }
    public static boolean areTheySameLine(star p1,star p2,star p3)
    {
       
        long area = p1.x*(p2.y - p3.y)+p2.x*(p3.y - p1.y) + p3.x*(p1.y-p2.y);
        return area == 0;
    }
 
 
}
