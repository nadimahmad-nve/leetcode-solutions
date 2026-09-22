#include <algorithm>

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
    int good; 

    void checkNode(TreeNode* root, int maxV) { 
        if (root == nullptr) return;
        
        if (root->val >= maxV) {
            good++; 
        }

        checkNode(root->left, max(maxV, root->val));
        checkNode(root->right, max(maxV, root->val));  
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0; 
        good = 0; 

        checkNode(root, root->val); 

        return good; 
    }
};