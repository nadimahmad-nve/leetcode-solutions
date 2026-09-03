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
public:
    int result = 0; 
    int count = 0; 

    void inorder(TreeNode* root, int k) {
        if (!root) return; 

        inorder(root->left, k); 

        count++;
        if (count == k) { 
            result = root->val;
            return;  
        }

        if (count < k) { 
            inorder(root->right, k); 
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k); 
        return result; 
    }
};
