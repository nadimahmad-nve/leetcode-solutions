class Solution:
    def isPalindrome(self, s: str) -> bool:
        right = len(s)-1
        left = 0 

        while left < right: 
            while left < right and not s[left].isalnum(): 
                left += 1
            
            while left < right and not s[right].isalnum():
                right -= 1
            
            if (s[right].lower() != s[left].lower()):
                return False
            else:
                right -= 1
                left += 1 
        
        return True
