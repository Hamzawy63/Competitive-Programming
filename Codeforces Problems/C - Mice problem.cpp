import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
 
public class Mice_problem {
    static final double E = 0.0000000000001;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
 
        int xb = sc.nextInt();
        int yb = sc.nextInt();
        int xt = sc.nextInt();
        int yt = sc.nextInt();
        if (xb == xt || yb == yt) {
            System.out.println(-1);
            return;
        }
 
        ArrayList<input> arr = new ArrayList<input>();
        for (int i = 0; i < n; i++) {
            arr.add(new input(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), xb, yb, xt, yt));
        }
 
        double maxIn = 0.0;
        double minOut = Double.MAX_VALUE;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).intersection == false) {
                System.out.println(-1);
                return;
            }
            //System.out.println(arr.get(i).t1 + ">>>>>" + arr.get(i).t2);
            if (arr.get(i).t1 > maxIn)
                maxIn = arr.get(i).t1;
            if (minOut > arr.get(i).t2)
                minOut = arr.get(i).t2;
 
        }
        if (minOut > maxIn)
            System.out.println(maxIn);
        else if (arr.size() == 1)
            System.out.println(0);
        else
            System.out.println(-1);
 
 
    }
 
    static class input {
        int xi;
        int yi;
        int vx;
        int vy;
        double t1;
        double t2;
        boolean intersection = true;
 
        public input(int xi, int yi, int vx, int vy, int a, int b, int c, int d) {
            this.xi = xi;
            this.yi = yi;
            this.vx = vx;
            this.vy = vy;
            if (!determineIntersection(a, b, c, d))
                intersection = false;
        }
 
        boolean equals(double d1, double d2) {
            return Math.abs(d1 - d2) < E;
        }
 
        boolean determineIntersection(int xb, int yb, int xt, int yt) {
            ArrayList<Double> arr = new ArrayList<Double>();
 
            if (vx == 0 && vy == 0) {
                if (xi > xb && xi < xt && yi > yb && yi < yt) {
                    t1 = 0.0;
                    t2 = Double.MAX_VALUE;
                    return true;
                } else {
                    return false;
                }
 
            }
            if (vx == 0) {
                if (xi == xb || xi == xt) {
                    return false;
                }
            }
            if (vy == 0) {
                if (yi == yb || yi == yt) {
                    return false;
                }
            }
 
 
            if (xi >= xb && xi <= xt && yi >= yb && yi <= yt) {
                arr.add(0.0);
            }
            double t, X, Y;
            t = (xb - xi) / (double) vx; // X bottom
            Y = yi + t * vy;
            if ((Y < yt && Y > yb) || equals(Y, yt) || equals(Y, yb)) {
                if (t > 0) arr.add(t);
            }
 
 
 
 
 
 
            t = (xt - xi) / (double) vx; /// X top
            Y = yi + t * vy;
            if ((Y < yt && Y > yb) || equals(Y, yt) || equals(Y, yb)) {
                if (t > 0) arr.add(t);
            }
 
 
 
 
            t = (yb - yi) / (double) vy;
            X = xi + t * vx;
            if ((X < xt && X > xb) || equals(X, xt) || equals(X, xb)) {
                if (t > 0) arr.add(t);
            }
 
            t = (yt - yi) / (double) vy;
            X = xi + t * vx;
            if ((X < xt && X > xb) || equals(X, xt) || equals(X, xb)) {
                if (t > 0) arr.add(t);
            }
            if (arr.size() < 2) {
                System.out.println(-1);
                System.exit(0);
 
            }
            Collections.sort(arr);
            if(arr.size() == 2 && Math.abs(arr.get(0) - arr.get(1)) < E     )
                intersection = false;
            t1 = arr.get(0);
            t2 = arr.get(arr.size() - 1);
 
            return true;
        }
 
 
    }
 
 
}
