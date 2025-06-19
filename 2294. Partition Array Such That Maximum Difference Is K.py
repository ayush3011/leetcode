class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        count = 1
        minVal = nums[0]

        for i in range(len(nums)):
            if nums[i] - minVal > k:
                count += 1
                minVal = nums[i]

        return count
