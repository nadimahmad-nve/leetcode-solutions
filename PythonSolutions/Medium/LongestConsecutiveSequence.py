class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if not nums:
            return 0

        max_length = 0 

        def countNums(s, startingNum):
            nonlocal max_length

            currLength = 0
            currNum = startingNum

            while (currNum in s):
                currLength += 1

                currNum += 1 

            max_length = max(max_length, currLength)
        
        s = set(nums)
        
        for i in s:
            if not (i-1) in s:
                # Found the start
                countNums(s, i) 

        return max_length

        
        