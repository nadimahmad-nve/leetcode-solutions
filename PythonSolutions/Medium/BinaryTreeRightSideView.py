from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: TreeNode | None) -> list[int]:
        # Breadth first search
        if root == None:
            return []

        q = deque()
        q.append(root)

        result = []

        while len(q) > 0: 
            size = len(q)
            rightMost = None

            for i in range(size):
                curr = q.popleft()
                rightMost = curr 

                if curr.left != None:
                    q.append(curr.left)
                
                if curr.right != None:
                    q.append(curr.right)
            
            result.append(rightMost.val)

        return result 