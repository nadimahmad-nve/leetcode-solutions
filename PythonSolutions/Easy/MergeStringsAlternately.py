class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        new_word = ""

        left = 0
        right = 0 

        while left < len(word1) and right < len(word2):
            if (left == right):
                new_word += word1[left]
                left += 1 
            elif (right < left): 
                new_word += word2[right]
                right += 1 
        
        if left < len(word1): 
            new_word += word1[left:]
        elif right < len(word2): 
            new_word += word2[right:]
        
        return new_word 