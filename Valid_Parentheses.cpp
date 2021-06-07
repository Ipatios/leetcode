/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include<iostream>
#include<string>
#include <stack>
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> result;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                result.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (i == 0 || result.empty() || result.top() != '(')
                {
                    return false;
                }
                result.pop();
            }
            else if (s[i] == ']')
            {
                if (i == 0 || result.empty() || result.top() != '[')
                {
                    return false;
                }
                result.pop();
            }
            else if (s[i] == '}')
            {
                if (i == 0 || result.empty() || result.top() != '{')
                {
                    return false;
                }
                result.pop();
            }
        }
        return result.empty();
    }
};
/*
**************** also correct solution it is just broken on leetcode ****************
#include<vector>
class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> result;
        if (s.length() <= 1)
        {
            return false;
        }
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                result.push_back(s[i]);
            }else
            {
                if (s[i] == ')' && result.back()=='(')
                {
                    result.pop_back();
                }

                if (s[i] == ']' && result.back() == '[')
                {
                    result.pop_back();
                }

                if (s[i] == '}' && result.back() == '{')
                {
                    result.pop_back();
                }
                
                
            }
            
            
        }
        return result.empty();
    }
};
*/