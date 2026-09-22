#include <limits>

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
    bool valid(TreeNode* root, long long left, long long right) {
        if (root == nullptr) return true; 

        if (!(root->val > left && root->val < right)) return false; 

        return valid(root->left, left, root->val) && valid(root->right, root->val, right); 
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long min_val = std::numeric_limits<long long>::min();
        long long max_val = std::numeric_limits<long long>::max();
        
        return valid(root, min_val, max_val);
    }  
};