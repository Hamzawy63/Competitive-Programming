 import java.util.Scanner;
    public class New_Year_and_Curling {
        static final double E = 0.00001;
 
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
 
            int n = sc.nextInt();
            int r = sc.nextInt();
            double[] y = new double[n];
            int arr[] = new int[n];
 
            for (int i = 0; i < n; i++) {
                arr[i] =sc.nextInt();
                double top = r; // if we make it 0 and subtract from the result will get WA (do not know why!!!)

















