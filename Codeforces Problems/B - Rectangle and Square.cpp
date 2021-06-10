import java.util.Scanner;
 
public class Rectangle_and_Square {
    static final double E = 0.00000005;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        point []arr = new point[9];
        for(int i = 1;i<9;i++)
        {
            arr[i] = new point(sc.nextInt() , sc.nextInt(),i);
        }
        point tmp;
        for(int i = 1;i<8;i++)
        {
            swap(arr , i ,8);
            for(int j = 1;j<8;j++)
            {
                swap(arr , j ,7);
                for(int k = 1;k<8;k++)
                {
                    swap(arr , j ,6);
                    for(int l = 1;l<8;l++)
                    {
                        swap(arr , l ,5);
                       // System.out.println(i+ ""+j+""+k+""+l);
 
                        if(isRectangle(arr[4],arr[1],arr[2],arr[3]) && isSquare(arr[4],arr[1],arr[2],arr[3]) && isRectangle(arr[5],arr[6],arr[7],arr[8]))
                        {
                            System.out.println("YES");
                            System.out.printf("%d %d %d %d\n",arr[1].index,arr[2].index,arr[3].index,arr[4].index);
                            System.out.printf("%d %d %d %d",arr[5].index,arr[6].index,arr[7].index,arr[8].index);
                            return;
                        }
                    }
 
                }
 
            }
        }
        System.out.println("NO");
 
    }
    public static boolean isRectangle(point p1 ,point p2,point p3,point p4 )
    {
        point points[] = {p1,p2,p3,p4};
        for(int i = 0 ;i<4;i++)
        {
            for(int j = i+1;j<4;j++)
            {
                for(int k = j+1;k<4;k++)
                {
                    if(!isRightAngled(points[i],points[j],points[k]))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
 
    public static boolean isSquare (point p1 ,point p2,point p3,point p4)
    {
 
        double l1 = Math.sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
        double l2 = Math.sqrt((p1.x - p3.x)*(p1.x - p3.x)+(p1.y - p3.y)*(p1.y - p3.y));
        double l3 = Math.sqrt((p1.x - p4.x)*(p1.x - p4.x)+(p1.y - p4.y)*(p1.y - p4.y));
 
        double Min = Math.min(l1,l2);
        double Max = Math.max(l1,Math.max(l2,l3));
        return Math.abs(Math.sqrt(2)*Min  - Max) <E;
    }
 
    static  class point
    {
        int x;
        int y;
        int index;
        point(int x , int y, int index)
        {
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }
    public static boolean isRightAngled(point p1 ,point p2 ,point p3 ) {
        if((p1.x == p2.x && p1.y == p2.y)||(p3.x == p2.x && p3.y == p2.y)||(p1.x == p3.x && p1.y == p3.y))
            return false;
 
        double l1 = Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2);
        double l2 = Math.pow(p2.x - p3.x, 2) + Math.pow(p2.y - p3.y, 2);
        double l3 = Math.pow(p1.x - p3.x, 2) + Math.pow(p1.y - p3.y, 2);
        double Max = Math.max(l1, Math.max(l2, l3));
        if ((Math.abs(Max - (l1 + l2 + l3 - Max)) <         E))
            return true;
        return false;
    }
    public static void swap(point[] arr , int  i , int j)
    {
        int tmpX = arr[j].x;
        int tmpY = arr[j].y;
        int tmpI = arr[j].index;
        arr[j].x = arr[i].x;
        arr[j].y = arr[i].y;
        arr[j].index = arr[i].index;
        arr[i].x = tmpX;
        arr[i].y = tmpY;
        arr[i].index = tmpI;
    }
 
 
}
 
