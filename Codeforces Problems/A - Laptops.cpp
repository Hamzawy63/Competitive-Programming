import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
 
public class Laptops {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        laptop[] arr = new laptop[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = new laptop(sc.nextInt(),sc.nextInt());
        }
        //Arrays.sort(bookArray, Comparator.comparing(Book::getName)
        Arrays.sort(arr, Comparator.comparing(laptop::getPrice));
        //System.out.println(Arrays.asList(arr));
        for(int i = 0;i<arr.length-1 ;i++)
        {
            if(arr[i+1].performance < arr[i].performance  ){
                System.out.println("Happy Alex");
                return;
            }
        }
        System.out.println("Poor Alex");
    }
 
    public static class laptop
    {
        int price;
        int performance;
 
        laptop(int a , int b)
        {
            price = a;
            performance = b;
        }
 
 
        public int getPrice() {
            return price;
        }
        @Override
        public String toString() {
            return
                    "Price=" + price + "And" +
                    ", performance=" + performance +
                     System.getProperty("line.separator");
        }
 
    }
 
 
}
