import java.util.Scanner;
 
public class Brains_Photos {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        String Lol = sc.nextLine(); // buffer
        boolean flag = true;
        for(int i = 0 ;i<n1 ;i++)
        {
            String tmp = sc.nextLine();
            tmp = tmp.toLowerCase().replaceAll("[wbg ]","");
            if(tmp.length() != 0)
                flag = false;
        }
 
        System.out.println(flag ? "#Black&White" :"#Color");
    }
}
