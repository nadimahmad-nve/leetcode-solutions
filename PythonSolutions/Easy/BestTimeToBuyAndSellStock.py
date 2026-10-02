class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = prices[0] 
        profit = 0 

        for i in range(1, len(prices)):
            minPrice = min(minPrice, prices[i])

            profit = max(prices[i]-minPrice, profit)
        
        return profit 