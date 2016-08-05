import java.lang.*;

public class main {
    private static boolean isPrime(int n) {
        if(n == 1)
            return false;

        for(int i=2; i<=Math.sqrt(n); i++)
            if(n%i == 0)
                return false;
        return true;
    }

    private static void sumOfPrimes(int n) {
        long result = 0;
        for(int i=2; i<n; i++)
            if(isPrime(i))
                result += i;

        System.out.println(result);
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        sumOfPrimes(2000000);

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
