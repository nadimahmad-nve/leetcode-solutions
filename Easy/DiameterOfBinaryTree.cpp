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
    int max_diameter = 0; 

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int left_height = dfs(node->left);
        int right_height = dfs(node->right);

        max_diameter = max(left_height+right_height, max_diameter); 

        return max(left_height, right_height) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }
};