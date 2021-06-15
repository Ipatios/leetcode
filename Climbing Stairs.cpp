/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

1 <= n <= 45
*/
/*
t will be the sum of this series
1+C(n-1,1)+C(n-2,2)+C(n-3,3)+......C(n-x,x) where x<n/2;
exaplanation:
there is 1 way when only one step is taken each time for n times to climb up.
next we take a double(2) step and all other single(1) steps, in dis case total number of times i need to take steps will be n-1.
do this recusively increasing the number of double steps taken and arraging those.


Consider F(N) is number of ways to get to the Nth step.
there are only two steps you can get there from: N-1 and N-2
All the ways you can get to the step (N-1) + the number of ways to get to the step N-2 will give you the total number of ways.
F(n) = F(n-1) + F(n-2).
And this looks like Fibonachi sequence.
This can be expanded to 3 ways of stepping leading into more complex problem
*/
class Solution
{
public:
    static int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        int i = 1, fn2 = 1, fn1 = 1, fn = 1;
        while (i++ < n)
            fn = fn1 + fn2, fn2 = fn1, fn1 = fn;
        return fn;
    }
};