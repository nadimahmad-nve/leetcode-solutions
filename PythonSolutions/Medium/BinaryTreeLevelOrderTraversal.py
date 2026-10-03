from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        q = deque()

        if not root:
            return []

        q.append(root)

        res = []

        while q: 
            currSize = len(q)
            level = []
            for i in range(currSize):
                x = q.popleft()
                level.append(x.val)

                if x.left != None: 
                    q.append(x.left)
                
                if x.right != None:
                    q.append(x.right)
                
            res.append(level)
        
        return res 