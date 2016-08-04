import java.lang.*;

public class main {
    public static void primeFactors(long n) {
        while(n%2==0) {
            System.out.print("2 ");
            n/=2;
        }

        for(long i=3; i<=(int)Math.sqrt(n); i++) {
            while(n%i==0) {
                System.out.print(i + " ");
                n/=i;
            }
        }

        if(n>2) {
            System.out.print(n);
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();


        primeFactors(600851475143L);

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
