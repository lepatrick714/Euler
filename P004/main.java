import java.lang.*;

public class main {

    private static boolean is_palindrome(int n) {
        int oldNum = n;
        int newNum = 0;

        while(n >= 1) {
            newNum = (newNum*10) + n%10;
            n/=10;
        }

        if(oldNum == newNum)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int a = 0;
        for(int i = 100; i<1000; i++) {
            for(int j = i; j<1000; j++) {
                int calc = i*j;
                if(calc > a && is_palindrome(calc)) {
                    a = calc;
                }
            }
        }

        System.out.println(a);


        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
