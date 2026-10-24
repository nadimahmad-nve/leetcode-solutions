from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left = 0 
        right = len(arr)-1 

        size = right - left + 1 

        while size > k: 
            rightDist = abs(arr[right] - x) 
            leftDist = abs(arr[left] - x)

            if rightDist > leftDist: 
                right -= 1 
            elif leftDist > rightDist:
                left += 1 
            else:
                right -= 1 
            
            size -= 1 
        
        return arr[left:right+1]