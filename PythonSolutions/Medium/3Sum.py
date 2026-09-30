class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # Need to fix a number, and then do Two Sum on the rest 
        # Results in O(n^2) time but this is best 
        # Sort it first 
        nums.sort()

        n = len(nums)
        res = []

        for i in range(n):
            chosenNum = nums[i]

            if i > 0 and nums[i] == nums[i-1]:
                # Duplicate found 
                continue 
            
            target = -chosenNum 
            temp = []

            left = i+1
            right = n-1 

            while (left < right): 
                theSum = nums[left] + nums[right]

                if theSum == target:
                    temp.append([chosenNum, nums[left], nums[right]])

                    left += 1 

                    while (left < right and nums[left] == nums[left-1]):
                        left += 1 

                    continue 
                
                if theSum < target:
                    left += 1 
                else: 
                    right -= 1 
            
            if temp != []:
                for sol in temp:
                    res.append(sol)
        
        return res