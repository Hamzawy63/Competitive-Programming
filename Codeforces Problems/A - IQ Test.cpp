import java.util.Scanner;
 
public class IQ_Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [][] arr = new int[4][4];
        for(int i  = 0 ; i<4;i++ )
        {
            String tmp = sc.nextLine();
           // System.out.println(tmp);
            for(int j = 0 ;j<4 ;j++)
            {
                if(tmp.charAt(j) == '.')
                    arr[i][j] = -1;
                else
                    arr[i][j] = 1;
            }
        }
        // start searching for the solition
        boolean found = false;
        for(int i = 0 ;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
              //  System.out.print(arr[i][j]+" ");
                if(arr[i][j] * arr[i+1][j+1] * arr[i][j+1] * arr[i+1][j] == -1)
                {
                    found = true;
                }else if(arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j])
                {
                    found = true;
                }
            }
           // System.out.println();
        }
        System.out.println(found ? "YES":"NO");
    }
}
