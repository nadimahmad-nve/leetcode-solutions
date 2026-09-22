#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> q; 
        vector<int> res; 

        q.push(root); 

        while(!q.empty()) {
            int n = q.size();
            TreeNode* x; 
            for(int i=0; i<n; i++) {
                x = q.front(); 

                q.pop();

                if (x->left != nullptr) { 
                    q.push(x->left); 
                }

                if (x->right != nullptr) { 
                    q.push(x->right); 
                } 
            }
            
            res.push_back(x->val); 
        }

        return res; 
    }
};