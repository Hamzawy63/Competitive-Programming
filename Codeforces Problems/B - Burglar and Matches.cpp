import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;
 
public class Sort_the_Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int m = sc.nextInt();
        container[] arr = new container[m];
        for(int i = 0 ;i<m;i++)
        {
            arr[i]= new container(sc.nextLong() , sc.nextInt());
        }
        Arrays.sort(arr);
        int res = 0;
 
        for(int i =0;i<arr.length && n>0;i++)
        {
 
            res+= (Math.min(arr[i].a , n))*arr[i].b;
            n-=Math.min(arr[i].a , n);
        }
        System.out.println(res);
 
 
    }
   static class container implements Comparable<container>
    {
        long a ;
        int b;
        container(long a , int b)
        {
            this.a = a;
            this.b = b;
        }
        @Override
        public int compareTo(container c )
        {
            return Integer.compare(c.b, this.b);
        }
    }
 
 
               
}
