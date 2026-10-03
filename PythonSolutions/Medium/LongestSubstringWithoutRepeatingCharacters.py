class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        x = set()
        maxLength = 0 

        left = 0
        right = 0

        while right < len(s):
            while s[right] in x:
                x.discard(s[left])
                left += 1

            x.add(s[right])

            maxLength = max(maxLength, right - left + 1)
            right += 1

        return maxLength