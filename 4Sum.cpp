/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/ 

// i is for the starting index
// j is for the second one
// and L,R is the 2 that changes with L being the third in line from left 
// and R the 4 from end of the vector (right to left)
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &num, int target) {
		sort(num.begin(), num.end());
		std::vector<std::vector<int>>result;
		if(num.size()<4){
			return result;
		}
		
		for (int i = 0; i < num.size() - 3; i++) {
			for (int j = i + 1; j < num.size() - 2; j++) {
				int L = j + 1;
				int R = num.size() - 1;

				while (L < R) {
					int sum = num[i] + num[j] + num[L] + num[R];
					if (sum == target) {
						std::vector<int> temp(4);
						temp[0] = num[i];
						temp[1] = num[j];
						temp[2] = num[L];
						temp[3] = num[R];
						result.push_back(temp);
						L++;
						R--;
					}else if (sum < target){
						L++;
					} else {
						R--;
					}
				}
			}
        };
		// to find and delete duplicates
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = result.size()-1;  j > i; j--)
			{
			if(result[i]==result[j]){
				result.erase(result.begin()+j);
			}	
			}
			
		}
		return result;
    }
};