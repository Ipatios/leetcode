/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/ 

import java.util.ArrayList;
import java.util.List;
/*
the combos method basically goes to the fisrt loop on possition 0 and calls it again
so on the next loop we have the array of letters being the array of the second number
of the string for example we have the number 23
on possition 1 letters will have the array of number 3 which is {d,e,f} so when goes
back to call the method its on possition 2==len so it adds up the stringbuilder in the list  
which has the first element of the 2D array number 2 index 0 and the first element
of the 2D array number 3 index 0
that goes on until index is equal to len at which point we go to the second letter of number
2 to find the combos
*/ 
class Solution {
    // first 2 in the 2D array are empty because 0,1 on the phone
    // doesnt have any characters
    final char[][] L = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
    {'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    public List<String> letterCombinations(String digits) {
        int len = digits.length();
        List<String> Answer = new ArrayList<>();
        if (len == 0) return Answer;
        combos(0, len, new StringBuilder(), Answer, digits);
        return Answer;
    }
// finishes when all the possitions are done with for loops 
    public void combos(int pos, int len, StringBuilder sb, List<String> Answer, String D) {
        if (pos == len) Answer.add(sb.toString());
        else {
            char[] letters = L[Character.getNumericValue(D.charAt(pos))];
            // adds to the stringbuilder the second letter to the combo
            // when finishes up it goes to the second character of 
            //  letters 2d array and does the matching all over again 
            // when all for loops finish from end to start then we 
            // have a return statement
            for (int i = 0; i < letters.length; i++)
                combos(pos+1, len, new StringBuilder(sb).append(letters[i]), Answer, D);
        }
    }
}