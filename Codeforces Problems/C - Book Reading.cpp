 
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























