class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0 
        high = x 

        ans = 0

        while low <= high:
            mid = low + (high-low)//2 

            if mid * mid == x:
                return mid 
            elif mid * mid > x:
                high = mid-1 
            elif mid * mid < x:
                low = mid+1 
                ans = mid 

        return ans