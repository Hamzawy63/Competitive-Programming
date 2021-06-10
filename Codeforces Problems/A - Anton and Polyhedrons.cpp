import java.util.Scanner;
 
public class Anton_and_Polyhedrons {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        long res =0;
        while(n-- >0)
        {
            char x = sc.nextLine().charAt(0);
            switch (x)
            {
                case 'T':
                    res+=4;
                    break;
                case 'C':
                    res+=6;
                    break;
                case 'O':
                    res+=8;
                    break;
                case 'D':
                    res+=12;
                    break;
                case 'I':
                    res+=20;
                    break;
 
            }
        }
        System.out.println(res);
    }
}
