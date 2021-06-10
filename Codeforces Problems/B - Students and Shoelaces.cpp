import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;
 
public class Students_and_Shoelaces {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n + 1][n + 1];
        int[] deg = new int[n + 1];
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr[x][y]++;
            arr[y][x]++;
            deg[x]++;
            deg[y]++;
        }
 
        int res = 0;
        boolean flag = true;
        while (flag) {
            flag = false;
            Stack<Integer> st = new Stack<Integer>();
            for (int i = 1; i < deg.length; i++) {
                if (deg[i] == 1) {
                    flag = true;
                    deg[i] = -1;
                    st.push(i);
 
                }
            }
            if(flag) res++;
            while(!st.isEmpty())
            {
                int i = st.pop();
                for (int j = 1; j < arr[0].length; j++) {
                    if (arr[i][j] == 1) {
                        arr[i][j] = 0;
                        deg[j]--;
                    }
                }
            }
        }
 
        System.out.println(res);
 
 
    }
}
