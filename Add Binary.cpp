/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
class Solution
{
public:
   static std::string addBinary(std::string A, std::string B)
    {
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        int n = A.length() >= B.length() ? A.length() : B.length();
        int carry = 0;
        std::string result = "";
        for (int i = 0; i < n; ++i)
        {
            /*
            a - '0' is equivalent to ((int)a) - ((int)'0'), 
            which means the ascii values of the characters are subtracted from each other. 
            Since 0 comes directly before 1 in the ascii table (and so on until 9), 
            the difference between the two gives the number that the character a represents.
            */ 
            int a = i < A.length() ? A[i] - '0' : 0;
            int b = i < B.length() ? B[i] - '0' : 0;
            int temp = a + b + carry;
            carry = temp / 2;
            result += std::to_string(temp % 2);
        }
        if (carry == 1)
            result += std::to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
