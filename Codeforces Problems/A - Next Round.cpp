import java.util.Scanner;
 
public class Young_Physicist {
    public static void main(String[] args) {
        int[] arr = new int[3];
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt();
        for(int i = 0 ;i<3*n;i++)
        {
            arr[i%3] += sc.nextInt();
        }
        if(arr[0] ==0&&arr[1] ==0&&arr[2] ==0)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
