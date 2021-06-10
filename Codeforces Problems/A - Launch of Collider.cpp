import java.util.Scanner;
 
public class Launch_of_Collider {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        sc.nextLine(); // buffer
        String d = sc.nextLine();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
 
        // WE KNOW THAT ONLY SEQUENCE 'RL' CAN MAKE COLLISIONS
        int res = arr[n-1] - arr[0];
        boolean collision = false;
        for (int i = 0; i < n - 1; i++) {
            if (d.charAt(i) == 'R' && d.charAt(i + 1) == 'L') {
                collision = true;
                int tmp = (arr[i + 1] - arr[i]) / 2;
                res = tmp < res ? tmp : res;
            }
        }
        if (!collision)
            System.out.println(-1);
        else
            System.out.println(res);
 
    }
}
