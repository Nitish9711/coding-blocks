
import java.util.Scanner;

public class UserInput {
    public static void main(String[] args) {

        // sc object to take input
        
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        
        System.out.println(x);
        double y = sc.nextDouble();
        System.out.println(y);
        
        String hello = sc.nextLine();
        System.out.println(hello);
        // object has to closed
        sc.close();




        int principal = 5000;
        // if we did not write f then java will treat it like double value
        float rate = 12.5f;
        int time = 12;

        float simpleIntrest = principal*rate*time/100;
        System.out.println("the simple intrest is " + simpleIntrest);
    }
}
