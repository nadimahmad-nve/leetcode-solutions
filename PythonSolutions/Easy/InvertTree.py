class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode | None) -> TreeNode | None:
        if root == None: 
            return 

        temp = root.right 
        root.right = self.invertTree(root.left)
        root.left = self.invertTree(temp)

        return root 