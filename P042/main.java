/*Credits goes to Kristian whom wrote the C# code on the 15th May 2011
 * http://www.mathblog.dk/project-euler-42-triangle-words/
 * This code has been transcribed to Java by Patrick Le on the 18th May 2016
 * This program is meant for educational purposes
 */

import java.lang.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class main {
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int result = 0;
        String inputFile = args[0];

        try {
            Scanner reader = new Scanner(new File(inputFile));
            reader.useDelimiter(",");
            String word = "";

            while(reader.hasNext()) {
                word = reader.next();
                word = word.substring(1, word.length()-1);

                //Kristian Algorithm Below
                int totalWordValue = 0;
                for(int i=0; i<word.length(); i++) {
                    totalWordValue+=(int)word.charAt(i)-64;
                }

                double wordsum = (Math.sqrt(1.0+8.0*(totalWordValue)) - 1.0) / 2.0;
                if(wordsum == ((int)wordsum)) {
                    result++;
                }
                //End of Kristian Algorithm
            }

            System.out.println("Total triangle words: " + result + ".");
        }
        catch(FileNotFoundException ex) {
            System.out.println("Unable to open file");
        }
        catch(IOException ex) {
            System.out.println("Error reading file");
        }

        long endTime = System.currentTimeMillis();
        long totalSpan = System.currentTimeMillis();

        System.out.println("Completed in " + totalSpan + " milliseconds.");

    }
}
