/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution
{
    void backtracking(int n, int open, int close, string str, vector<string> &result)
    {
        if (close == n)
        {
            result.emplace_back(str);
            return;
        }
        else
        {
            if (open < n)
            {
                str += '(';
                backtracking(n, open + 1, close, str, result);
                str.pop_back();
            }
            if (open > close)
            {
                str += ')';
                backtracking(n, open, close + 1, str, result);
                str.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        if (n > 0)
            backtracking(n, 0, 0, "", result);
        return result;
    }
};
