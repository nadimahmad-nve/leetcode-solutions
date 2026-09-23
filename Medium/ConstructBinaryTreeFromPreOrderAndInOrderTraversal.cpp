#include <vector> 

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) { 
        if (preStart > preEnd || inStart > inEnd) { 
            return nullptr; 
        }

        TreeNode* root = new TreeNode(preorder[preStart]); 
        int posOfRoot; 

        for(int i = inStart; i <= inEnd; i++) { 
            if(inorder[i] == root->val) { 
                posOfRoot = i; 
                break;
            }
        }

        int numsLeft = posOfRoot - inStart;

        root->left = helper(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, posOfRoot - 1);
        root->right = helper(preorder, inorder, preStart + numsLeft + 1, preEnd, posOfRoot + 1, inEnd);

        return root; 
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size()-1;
        return helper(preorder, inorder, 0, n, 0, n); 
    }
};