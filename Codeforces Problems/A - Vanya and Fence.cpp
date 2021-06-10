import java.util.Scanner;
public class main
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int hence = sc.nextInt(); ///height of the hence
        int sum = 0; ///total width of the road
        for(int i = 0 ;i<n;i++)
        {
            int tmp = sc.nextInt();
            if(tmp > hence)
                sum+=2;
            else 
                sum+=1;
        }
        System.out.println(sum);
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
