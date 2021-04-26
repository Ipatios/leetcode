/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
*/ 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
// index i is the starting idex 
// index j is the middle number 
// and k is the last one
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
    ArrayList<List<Integer>> MyList = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int j = i + 1;
            int k = nums.length - 1;
           // checks for duplicates for index i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
     
            while (j < k) {
                // checks for duplicates for index k
                if (k < nums.length - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
     
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    ArrayList<Integer> l = new ArrayList<>();
                    l.add(nums[i]);
                    l.add(nums[j]);
                    l.add(nums[k]);
                    MyList.add(l);
                    j++;
                    k--;
                }
            }
        }
     
        return MyList;
    }
}
