class Solution:
    def getConcatenation(self, nums: list[int]) -> list[int]:
        res = []

        for i in range(2):
            for j in nums:
                res.append(j)
        
        return res 