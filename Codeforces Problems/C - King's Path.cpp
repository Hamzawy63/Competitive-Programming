import java.awt.*;
import java.util.*;
 
public class Kings_Path {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        int n = sc.nextInt();
        //HashMap<Integer, LinkedList<Point>> hm = new HashMap<Integer, LinkedList<Point>>();
        HashMap<Point , Boolean> hm = new HashMap<Point,Boolean>();
        hm.put(new Point(x1,y1) , true);
 
        while (n-- > 0) {
            int r = sc.nextInt();
            int c1 = sc.nextInt();
            int c2 = sc.nextInt();
            for (int i = c1; i <= c2; i++) {
                hm.put(new Point(r, i),false);
            }
        }
 
        Queue<Point> q = new LinkedList<Point>();
        Queue<Integer> path = new LinkedList<Integer>();
        q.add(new Point(x1, y1));
        path.add(0);
        int size = -1;
        while (!q.isEmpty()) {
            Point tmp = q.remove();
            int  length = path.remove();
            if(tmp.x == x2 && tmp.y == y2 ) {
                size = length;
                break;
            }else
            {
                for(int i = -1 ;i<2;i++)
                {
                    for(int j = -1;j<2;j++)
                    {
                        int x = tmp.x  + i;
                        int y = tmp.y + j;
                        if(x<=1e9 && x>0 && y<=1e9 && y>0 && hm.get(new Point(x,y))!=null && hm.get(new Point(x,y))!= true )
                        {
                            q.add(new Point(x,y));
                            path.add(length+1);
                            hm.put(new Point(x,y) , true);
                        }
                    }
                }
            }
 
        }
        System.out.println(size);
 
 
 
    }
}
