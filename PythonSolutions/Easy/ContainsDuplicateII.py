class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        s = set()
        left = 0

        for right in range(len(nums)):
            if right - left > k:
                s.discard(nums[left])
                left += 1
            
            if nums[right] in s:
                return True

            s.add(nums[right])
            
        return False