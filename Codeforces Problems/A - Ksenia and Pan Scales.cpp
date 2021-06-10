import java.util.Scanner;
 
public class Ksenia_and_Pan_Scales {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
 
        String l = s1.substring(0, s1.indexOf('|'));
        String r = s1.substring(s1.indexOf('|'));
 
 
 
 
        int left = s1.substring(0, s1.indexOf('|')).length();
        int right = s1.substring(s1.indexOf('|')).length() - 1;
        int tmp = Math.abs(left - right);
        if ((s2.length() - tmp) % 2 == 0 &&(s2.length() - tmp)>=0) {
            while ( s2.length() != 0) {
                if (l.length()+1 < r.length()) {
                    l = s2.charAt(0) + l;
                    s2 = s2.substring(1);
                } else if (l.length() > (r.length()-1)) {
                    r = r + s2.charAt(0);
                    s2 = s2.substring(1);
                } else {
                    l =   s2.substring(0,s2.length()/2)+ l ;
                    r =   r+ s2.substring(s2.length()/2);
                    break;
                }
 
            }
            System.out.println(l+r);
 
 
        } else {
            System.out.println("Impossible");
        }
 
    }
}
