import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[]arr = sc.nextLine().toCharArray();
        int res = 0;
        int lastBear = 0;
        for (int i = 0; i+3 <arr.length ; i++) {
            if(arr[i] == 'b'&& arr[i+1] == 'e'&& arr[i+2] == 'a'&& arr[i+3] == 'r') {
                res += (i + 1 - lastBear) * (arr.length - i - 3);
                lastBear =  i+1;
            }
 
        }
        System.out.println(res);
 
 
    }
 
 
}
