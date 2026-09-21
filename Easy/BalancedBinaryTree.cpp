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
    pair<bool, int> dfs(TreeNode* root) { 
        if (root==nullptr) {
            return {true, 0}; 
        }

         pair<bool, int> left = dfs(root->left); 
         pair<bool, int> right = dfs(root->right); 

         bool valid = left.first && right.first && (abs(left.second-right.second) <= 1); 

         pair<bool, int> result = {valid, max(left.second, right.second)+1}; 
         
         return result;
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first; 
    }
};