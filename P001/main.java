import java.lang.*;

public class main {
    public static int calculateTotal(int n) {
        return (n*(n+1))/2;
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int find3 = 3*calculateTotal(333);
        int find5 = 5*calculateTotal(199);
        int findRepeats = 15*calculateTotal(66);
        int total = find3+find5-findRepeats;

        System.out.println(total);

        long endTime = System.currentTimeMillis();
        long totalSpan = endTime - startTime;
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
