class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        minLength = float('inf')
        left = 0
        currSum = 0 

        for right in range(len(nums)):
            currSum += nums[right]

            while currSum >= target:
                minLength = min(minLength, right - left + 1)
                currSum -= nums[left]
                left += 1
                
        if minLength == float('inf'):
            return 0
            
        return minLength