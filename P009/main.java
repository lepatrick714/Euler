import java.lang.*;
import java.math.*;

public class main {
    private static void findProduct() {
        int sum = 1000;

        for(int a=1; a<sum/3; a++) {
            for(int b=a+1; b<sum/2; b++) {
                int c = sum-a-b;
                if(a*a + b*b == c*c) {
                    System.out.println(a*b*c);
                }
            }
        }
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        findProduct();

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
