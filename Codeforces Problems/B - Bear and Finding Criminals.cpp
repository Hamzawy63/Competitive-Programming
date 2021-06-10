import java.util.Scanner;
 
public class Bear_and_Finding_Criminals {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int []arr = new int[n];
 
        for (int i = 0 ;i<n ;i++)
            arr[i] = sc.nextInt();
 
 
        int count = ( arr[k-1] == 1) ? 1 : 0;
        for(int i=1  ;i<=Math.max(k,n-k)   ;i++)
        {
            int c = 0 ,valid = 0 ;
            if(valid((k-1) -i,n) && arr[(k-1) -i] == 1)
                c++;
 
            if(valid((k-1) +i,n) && arr[(k-1) +i] == 1)
                c++;
 
            if(c == 2)
                count+=2;
            else if (c == 1 )
            {
                if(valid((k-1) -i,n)  ^ valid((k-1) +i,n))
                    count++;
 
            }
 
        }
        System.out.println(count);
    }
    public static boolean valid(int i ,int n)
    {
        return i>=0  && i<n ;
    }
}
