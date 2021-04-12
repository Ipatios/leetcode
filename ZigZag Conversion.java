import java.lang.*;

class Solution
{
     
    // Function for zig-zag Concatenation
    private static String zigZagConcat(String s, int numRows)
    {
 
        // Check is numRows is less
        // or equal to 1
        if (numRows <= 1)
        {
            return s;
        }
 
        StringBuilder result = new StringBuilder();
 
        // Iterate rowNum from 0 to numRows - 1
        for (int rowNum = 0; rowNum < numRows; rowNum++)
        {
            int i = rowNum;
            boolean up_in_mid = true;
           
            // Iterate i till s.length() - 1
            while (i < s.length())
            {
 
                result = result.append(s.charAt(i));
               
                // Check is rowNum is 0 or numRows - 1
                if (rowNum == 0 || rowNum == numRows - 1)
                {
                    i += (2 * numRows - 2);
                }
                else
                {
                    if (up_in_mid)
                    {
                        i += (2 * (numRows - rowNum) - 2);
                    }
                    else
                    {
                        i += rowNum * 2;
                    }
                    up_in_mid ^= true;
                }
            }
        }
        return result.toString();
    }
 
    // Driver Code
    public static void main(String[] args)
    {
        String str = "PAYPALISHIRING";
        int numRows = 4;
        System.out.println(zigZagConcat(str, numRows));
    }
}