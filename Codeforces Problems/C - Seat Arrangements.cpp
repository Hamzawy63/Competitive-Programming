import java.util.Scanner;
 
public class Seat_Arrangements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // row
        int m = sc.nextInt(); // column
        int k = sc.nextInt();
        sc.nextLine();
        char[][] arr = new char[n][m];
        int res = 0;
        int dotNumber = 0;
 
        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            int seq = 0;
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp.charAt(j);
                if (arr[i][j] == '.') {
                    dotNumber++;
                    seq++;
                    if ((j + 1 == m)) {
                        res += find_ways(k, seq);
                    }
 
                } else if (arr[i][j] == '*' || (j + 1 == m)) {
                    res += find_ways(k, seq);
                    seq = 0;
                }
            }
        }
        if(k == 1)
        {
            System.out.println(dotNumber);
            return;
        }
        for (int j = 0; j < m; j++) {
            int seq = 0;
            for (int i = 0; i < n; i++) {
                if(arr[i][j] == '.')
                    seq++;
                if(arr[i][j] == '*' || (i+1) == n)
                {
                    res+= find_ways(k,seq);
                    seq= 0;
                }
 
            }
        }
        System.out.println(res);
    }
 
    public static boolean valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
 
    public static int find_ways(int k, int seq) {
        if (k > seq)
            return 0;
        return 1 + (seq - k);
    }
}
