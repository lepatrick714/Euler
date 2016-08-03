import java.lang.*;
import java.util.*;

public class main {







    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int total = 0;
        Stack temp = new Stack();
        temp.push(1);
        temp.push(2);
        int secondNum = 0;

        while(secondNum < 4000000) {
            secondNum = (Integer)temp.pop();
            int firstNum = (Integer)temp.pop();

            if(secondNum%2 == 0) {
                total+=secondNum;
            }

            temp.push(secondNum);
            temp.push(firstNum+secondNum);
        }

        System.out.println(total);
        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();
        System.out.println("Completed in " + totalSpan + " milliseconds.");
    }
}
