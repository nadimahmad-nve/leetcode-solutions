class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hash_map = {}

        for i in range(0,len(nums)):
            numNeeded = target - nums[i]

            if(numNeeded in hash_map):
                return [i, hash_map[numNeeded]]
            else:
                hash_map[nums[i]] = i  
