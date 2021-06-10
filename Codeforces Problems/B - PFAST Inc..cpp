 
 
import java.util.*;
 
public class CF_PFAST_Inc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine(); // buffer
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLine();
        }
        String hate[][] = new String[m][2];
        for (int i = 0; i < m; i++) {
            hate[i][0] = sc.next();
            hate[i][1] = sc.next();
        }
        // try all pairs
 
        int size = 1 << n;
        ArrayList<String> res[] = new ArrayList[size];
 
 
        for (int i = 0; i < size; i++) {
            res[i] = new ArrayList<String>();
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    res[i].add(arr[j]);
                }
            }
        }
 
        int resIndex = -1;
        int resLengh = -1;
        for (int i = 0; i < size; i++) {
            // check if if there are people who hate each other in each team (subset)
            boolean flag = true;
            target:
            for (int j = 0; j < res[i].size(); j++) {
                for (int k = 0; k < res[i].size(); k++) {
                    String s1 = res[i].get(j);
                    String s2 = res[i].get(k);
                    if (isTheyHateEachOther(s1, s2, hate)) {
                        flag = false;
                        break target;
                    }
                }
            }
            if (flag) {
                if (resLengh < res[i].size()) {
                    resIndex = i;
                    resLengh = res[i].size();
                }
            }
        }
        System.out.println(resLengh);
        Collections.sort(res[resIndex]);
        for (String tmp : res[resIndex]) {
            System.out.println(tmp);
        }
    }
 
    public static boolean isTheyHateEachOther(String s1, String s2, String hate[][]) {
        for (int i = 0; i < hate.length; i++) {
            if ((s1.equals(hate[i][0] ) && s2.equals(hate[i][1])) || (s2.equals(hate[i][0]) &&s1.equals(hate[i][1]) ))
                return true;
        }
        return false;
    }
 
 
}
