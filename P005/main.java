import java.lang.*;

public class main {
    private static boolean checkMultiple(int n) {
        for(int i=2; i<=20; i++)
            if(n%i != 0)
                return false;
        return true;
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int ctr = 20;
        while(true) {
            if(checkMultiple(ctr))
                break;
            ctr+=20;
        }

        System.out.println(ctr);


        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
