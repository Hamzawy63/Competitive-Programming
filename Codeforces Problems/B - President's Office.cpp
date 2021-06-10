 
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
 
public class Presidents_Office {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        char office = sc.next().charAt(0);
        char[][] arr = new char[r][c];
        TreeSet<Character> res = new TreeSet<Character>();
        for (int i = 0; i < r; i++) {
            String s = sc.next();
            for (int j = 0; j < s.length(); j++) {
                arr[i][j] = s.charAt(j);
            }
        }
        for (int i = 0; i < r; i++) {
 
            for (int j = 0; j < c; j++) {
                if(arr[i][j] == office)
                {
                    if(arr[i][Math.min(j+1,c-1)]!= office && arr[i][Math.min(j+1,c-1)]!= '.' )
                        res.add(arr[i][Math.min(j+1,c-1)]);
 
                    if(arr[i][Math.max(j-1,0)]!= office && arr[i][Math.max(j-1,0)]!= '.')
                        res.add(arr[i][Math.max(j-1,0)]);
 
                    if(arr[Math.min(i+1,r-1)][j]!= office && arr[Math.min(i+1,r-1)][j]!= '.')
                        res.add(arr[Math.min(i+1,r-1)][j]);
 
                    if(arr[Math.max(i-1,0)][j]!= office && arr[Math.max(i-1,0)][j]!= '.')
                        res.add(arr[Math.max(i-1,0)][j]);
                }
            }
        }
        System.out.println(res.size());
    }
}
