class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: TreeNode | None, subRoot: TreeNode | None) -> bool:
        if root == None:
            return False

        # Go through each node, and check if same tree
        def isSameTree(tree1, tree2):
            if (tree1 == None and tree2 == None):
                return True
            
            if (tree1 == None):
                return False

            if (tree2 == None):
                return False

            if (tree1.val != tree2.val): 
                return False
            
            return isSameTree(tree1.right, tree2.right) and isSameTree(tree1.left, tree2.left)

        return isSameTree(root, subRoot) or self.isSubtree(root.right, subRoot) or self.isSubtree(root.left, subRoot)
