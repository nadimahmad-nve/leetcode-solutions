class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:

        def check(piles, k, h):
            hours = 0 

            for val in piles:
                hours += val // k 
                if (val % k != 0):
                    hours += 1 

            return hours <= h 
        
        low = 1
        high = max(piles)
        speed = high 

        while low <= high: 
            mid = (low+high)//2

            if (check(piles, mid, h)):
                # Can we go lower?
                high = mid-1 
                speed = mid 
            else:
                # We were unsuccessful, we need to go higher
                low = mid+1 
             
        return speed