import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
public class Letters_Cyclic_Shift {
    static String alph = "abcdefghijklmnopqrstuvwxyz";
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    public static void main(String[] args) {
 
        FastReader sc = new FastReader();
        String in = sc.nextLine();
        /**
        int start = in.indexOf('a');
        int end = -1;
        if(start != -1)
            end = in.indexOf('a', start + 1);
 
 
 
                System.out.println(in.substring(0, in.length() - 1) + 'z');
        } else if (start == 0) {
            if (end == -1) {
                String modified = replace(in.substring(1));
                System.out.println('a' + modified);
            } else //  there are an end
            {
                int j = 0;
                while (in.charAt(j) == 'a') {
                    j++;
                }
                if ((in.indexOf('a', j)!= -1)) {
                    String modified = replace(in.substring(j,in.indexOf('a', j)));
                    System.out.println(in.substring(0, j) + modified + in.substring(in.indexOf('a', j)));
                } else {
                    String modified = replace(in.substring(j));
                    System.out.println(in.substring(0, j ) + modified);
                }
 
            }
        } else if (start == -1) {
            System.out.println(replace(in));
        } else {
            String modified = replace(in.substring(0, start));
            System.out.println(modified + in.substring(start));
        }
         **/
        for(int i = 0 ;i<in.length();i++)
        {
            if(in.charAt(i) == 'a')
            {
                /// all are 'a' so we have to replace the last one
                /// there are bunch of letters between
                ///
 
                while( i < in.length()-1 && in.charAt(i) == 'a') {
                    System.out.print('a');
                    i++;
 
 
                }
                if(in.charAt(i) =='a')
                    System.out.print('z');
                else {
 
                    int j = i;
                    for (j = i; j < in.length() && in.charAt(j) != 'a'; j++) {
                        System.out.print(replace(in.charAt(j)));
                    }
                    for(int k = j ;k<in.length();k++)
                    {
                        System.out.print(in.charAt(k));
                    }
                    break;
                }
 
            }else
            {
                while( i < in.length() && in.charAt(i) != 'a' )
                {
                    System.out.print(replace(in.charAt(i)));
                    i++;
                }
                for(int j = i ;j<in.length();j++)
                    System.out.print(in.charAt(j));
                break;
 
            }
 
        }
 
 
 
    }
 
    public static String replace(String in) {
        String out = "";
        for (int i = 0; i < in.length(); i++) {
            int newIndex = in.charAt(i) - 'a' == -1 ? 25 : in.charAt(i) - 'a' - 1;
            out += alph.charAt(newIndex);
        }
        return out;
    }public static char replace(char in) {
 
        if(in == 'a')
            return 'z';
        int newIndex = in - 'a' == -1 ? 25 : in - 'a' - 1;
        return  alph.charAt(newIndex);
 
 
    }
 
}
