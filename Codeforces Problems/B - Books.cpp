import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
 
public class Books {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
 
        //long arr[] = new long[n];
        Deque<Long> deq = new LinkedList<Long>();
 
        long length=0;
        long sum=0;
        for(int i = 0 ;i<n ;i++)
        {
            long tmp  = sc.nextLong();
            sum+=tmp;
            deq.addLast(tmp);
            while(sum > k)
            {
                sum-= deq.removeFirst();
            }
            length = Math.max(length , deq.size());
        }
        System.out.println(length);
    }
 
}
 
