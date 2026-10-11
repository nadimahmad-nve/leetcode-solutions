class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        majority = None
        count = 0 

        for num in nums: 
            if count == 0: 
                majority = num
            
            if num == majority:
                count += 1
            else:
                count -= 1 
                
        return majority
        