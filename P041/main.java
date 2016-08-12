import java.lang.*;
import java.math.*;

public class main {
    private static boolean is_prime(int a) {
        if(a == 1)
            return false;

        for(int i=2; i<=(int)Math.sqrt(a); i++)
            if(a%i==0)
                return false;
        return true;
    }

    private static boolean isPandigital(int a) {
        String stringTemp = String.valueOf(a);
        String[] list = new String[stringTemp.length()-1];

        for(int i=0; i<stringTemp.length(); i++) {
            int yes = stringTemp[i];
            System.out.println(yes);
        }

        return true;
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();


        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();

        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
