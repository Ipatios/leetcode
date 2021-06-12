/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/
class Solution
{
public:
    int sqrt(int x)
    {
        if (x <= 1)
            return x;
        int low = 0;
        int high = x;
        int temp;
        while ((high - low) > 1)
        {
            temp = low + (high - low) / 2;
            // if the square root is perfect 
            // for example 8^2=64(so we put x=64)
            // then temp will be 8 and 64/8=8
            if (temp == (x / temp))
                return temp;
            
             if (temp > (x / temp))
                high = temp;
             // if temp < (x / temp) then low =temp
            //  if its not perfect square then it will take the lower number
             else
                 low = temp;
        }
        return low;
    }
};
