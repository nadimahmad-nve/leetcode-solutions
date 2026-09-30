class Solution:
    def maxArea(self, height: list[int]) -> int:
        n = len(height)
        left = 0
        right = n-1 
        maxArea = 0 

        while(left < right):
            currArea = min(height[left], height[right]) * (right-left)
            maxArea = max(currArea, maxArea)

            if (height[left] < height[right]): 
                left += 1 
            else: 
                right -= 1 

        return maxArea  
