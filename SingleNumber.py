# XORing would be better 
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        i = 0
        if len(nums) == 0:
            return 0

        nums.sort()
        
        while i+1 < len(nums):
            if nums[i] != nums[i+1]:
                return nums[i]
            else:
                i+=2
        
        return nums[len(nums) - 1 ] 

def main():
    nums = [4,1,2,1,2]
    solution = Solution()
    print(solution.singleNumber(nums))

if __name__ == "__main__":
    main()

