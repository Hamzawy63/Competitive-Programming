   
 
    import java.util.Scanner;
 
    public class DivisibilitybyEight {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String s = sc.nextLine();
            for (int i = 0; i < s.length(); i++) {
                String s2 = "" + s.charAt(i);
                if (Integer.parseInt(s2) % 8 == 0) {
                    System.out.println("YES");
                    System.out.println(s2.replaceFirst("^0+(?!$)", ""));
                    return;
                }
                for (int j = i+1; j < s.length(); j++) {
 
                    s2 =  "" + s.charAt(i)+s.charAt(j);
                    if (Integer.parseInt(s2) % 8 == 0) {
                        System.out.println("YES");
                        System.out.println(s2.replaceFirst("^0+(?!$)", ""));
                        return;
                    }
                    for (int k = j+1; k < s.length(); k++) {
                        s2 =  "" + s.charAt(i)+s.charAt(j)+s.charAt(k);
                        if (Integer.parseInt(s2) % 8 == 0) {
                            System.out.println("YES");
                            System.out.println(s2.replaceFirst("^0+(?!$)", ""));
                            return;
                        }
                    }
                }
            }
            System.out.println("NO");
        }
    }
