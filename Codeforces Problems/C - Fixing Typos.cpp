import java.util.Scanner;
/// submit the code again to appear in a2oj
 
public class Fixing_Typos {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] arr = sc.nextLine().toCharArray();
        boolean repeat = false;
        for (int i = 0; i < arr.length; ) {
            if (i < arr.length - 1 && arr[i] == arr[i + 1]) {
                int j = i;
                while (j < arr.length && arr[j] == arr[i]) {
                    j++;
                }
                if (repeat) {
                    System.out.print(arr[i]);
                    repeat = false;
                } else {
                    System.out.print(arr[i] + "" + arr[i]);
                    repeat = true;
                }
                i = j;
            } else {
                repeat = false;
                System.out.print(arr[i]);
               
                i++;
            }
        }
    }
 
    public static int carry(int sequence) {
        return sequence < 3 ? sequence : 2;
 
 
    }
}
