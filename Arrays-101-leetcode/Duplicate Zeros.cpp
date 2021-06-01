/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
*/ 
class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int sz = arr.size(), i = sz - 1;
        while (i >= 0)
        {
            
            if (arr[i])
            {
                
            }
            else
            {
                arr.insert(arr.begin() + i, 0);//inserts on i and pushes everything right and makes the size of arr +1 bigger until the pop 
                arr.pop_back();
            }
            --i;
        }
    }
};
