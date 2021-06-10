 
 
import java.util.Scanner;
 
public class Caisa_and_Pylons {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = sc.nextInt();
        int energy  = res;
        int last = 0;
        /**
        int []arr = new int[n];
        for(int i = 0 ;i<n;i++ )
        {
            arr[i]= sc.nextInt();
 
        }
        res = arr[0];
        for(int i= 0 ;i<n-1;i++)
        {
            arr[i] = arr[i] - arr[i+1];
            if(arr[i]<0)
                sum+=arr[i];
 
        }
            System.out.println(res - sum);
         **/
 
        for(int i = 0 ;i<n-1;i++ )
        {
           int tmp = sc.nextInt();
           energy+=last -tmp;
           if(energy<0)
           {
               res-=energy;
               energy = 0;
           }
           last = tmp;
        }
        System.out.println(res);
    }
}
