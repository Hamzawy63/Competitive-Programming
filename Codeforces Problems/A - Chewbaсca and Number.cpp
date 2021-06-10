import java.util.Scanner;
 
public class chewbacca_and_Number {
 
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            int tmp = Character.getNumericValue(arr[i]);
            if (tmp > 4)
                arr[i] = Character.forDigit(9 - tmp, 10);
 
        }
        if (arr[0] == '0')
            arr[0] = '9';
 
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
 
    }
 
}
