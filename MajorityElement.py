from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]


# for testing purposes
def main():
    nums = [2, 2, 1, 1, 1, 2, 2]
    sol = Solution()
    print(sol.majorityElement(nums))
    return


if __name__ == "__main__":
    main()
