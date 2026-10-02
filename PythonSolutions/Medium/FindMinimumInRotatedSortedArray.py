class Solution:
    def findMin(self, nums: list[int]) -> int:
        low = 0 
        high = len(nums)-1
        ans = nums[0]

        while (low<=high):
            if (nums[low] < nums[high]):
                return min(ans, nums[low])

            mid = (low+high) // 2
            ans = min(ans, nums[mid]) 

            if(nums[mid] < nums[low]):
                high = mid-1 
                # Out of order. We are in the right section
            elif(nums[mid] >= nums[low]):
                # We are in the left section
                low = mid+1
        
        return ans 