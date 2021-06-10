import java.util.Scanner;
 
public class Good_Number {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
 
        sc.nextLine(); // buffer
        int res = 0;
        for (int i = 0; i < n; i++) {
 
            int[] arr = new int[k + 1];
            boolean flag = true;
            String s = sc.nextLine();
            // start playing
            for (int j = 0; j < s.length(); j++) {
                int tmp = Character.getNumericValue(s.charAt(j));
                if(tmp > k)
                    continue;
                arr[tmp] = 1;
            }
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] == 0)
                    flag = false;
            }
            res = flag == true ? (res + 1) : (res);
 
        }
        System.out.println(res);
 
 
    }
}
