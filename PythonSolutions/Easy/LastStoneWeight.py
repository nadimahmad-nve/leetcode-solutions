import heapq

class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        max_heap = []
        heapq.heapify(max_heap)

        for i in stones:
            heapq.heappush(max_heap, -i)
        
        while len(max_heap) > 1: 
            x = -heapq.heappop(max_heap)
            y = -heapq.heappop(max_heap)

            if (x != y):
                heapq.heappush(max_heap, -(abs(y-x))) 
            
        if len(max_heap) == 1:
            return -heapq.heappop(max_heap)
        else:
            return 0 