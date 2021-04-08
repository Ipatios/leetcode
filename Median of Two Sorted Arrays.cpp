/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
*/ 

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
       std::vector<int> mine;
        double end,sum1,sum2;
        copy(nums1.begin(),nums1.end(),back_inserter(mine));
        copy(nums2.begin(),nums2.end(),back_inserter(mine));
        sort(mine.begin(),mine.end());
        sum1=mine[(mine.size()/2)];
        sum2=mine[((mine.size()-1)/2)];
        if(mine.size()%2 !=0){
            end=mine[(int)(mine.size()/2)];
        }else{
            end=(sum1+sum2)/2;
        }
       return end;
    }
};