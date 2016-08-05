import java.lang.*;

public class main {
    private static boolean isPrime(int n) {
        for(int i=2; i<=(int)Math.sqrt(n/2); i++)
            if(n%i == 0)
                return false;
        return true;
    }

    private static void findPrimeNumber(int n) {
        int result = 0;
        int ctr = 0;
        int start = 2;

        while(ctr != n) {
            if(isPrime(start)) {
                result = start;
                ctr++;
            }
            start++;
        }
        System.out.println(result);
    }


    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        findPrimeNumber(10001);

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
