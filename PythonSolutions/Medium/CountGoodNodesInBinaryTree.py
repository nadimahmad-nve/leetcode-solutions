class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        gNodes = 0

        def helper(root, maxVal): 
            nonlocal gNodes

            if not root:
                return 0 
            
            if(root.val >= maxVal):
                gNodes += 1 
                maxVal = root.val
            
            if root.right:
                helper(root.right, maxVal)
            
            if root.left:
                helper(root.left, maxVal)
        
        helper(root, root.val)
        return gNodes