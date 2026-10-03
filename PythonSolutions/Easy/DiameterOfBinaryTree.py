class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        maxD = 0

        def depth(node):
            nonlocal maxD
            
            # Base case: depth of an empty tree is 0
            if not node:
                return 0

            left_depth = depth(node.left)
            right_depth = depth(node.right)
            
            maxD = max(maxD, left_depth + right_depth)
            
            # Return the depth of the tree rooted at this node
            return 1 + max(left_depth, right_depth)

        depth(root)
        return maxD