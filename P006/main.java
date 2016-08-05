import java.lang.*;

public class main {

    private static void findDifference(int n) {
        int result = 0;

        int squared = (int)(2*Math.pow(n, 3) + 3*Math.pow(n, 2) + n)/6;
        int addSquared = (int)Math.pow((n*(n+1))/2, 2);

        result = addSquared-squared;
        System.out.println(addSquared + " - " + squared + " = " + result);
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        findDifference(100);

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
