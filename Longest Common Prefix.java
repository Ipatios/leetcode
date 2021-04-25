/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/ 
import java.util.Arrays;
 class Solution {
    public String longestCommonPrefix(String strs[]) {
    int size = strs.length;
    // The longest common prefix of an empty strs is "" or
    // The longest common prefix of an strs containing 
    // only one element is that element itself.
    if (size == 0 || size == 1){
     return strs[0]; 
    }
      // Sort the strs
      Arrays.sort(strs);
       int length = strs[0].length();
       StringBuilder res = new StringBuilder();
       // Comapre the first and the last strings character
       // by character.
       for(int i = 0; i < length; i++){
         // If the characters match, append the character to the result.
         if(strs[0].charAt(i) == strs[size - 1].charAt(i)){
           res.append(strs[0].charAt(i));
         }
         // Else, stop the comparison.
         else{
           break;
         }
       }
       return res.toString();
    } 
}
