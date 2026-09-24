#include <vector>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res; 

    void backtrack(int currSum, vector<int>& currNums, int target, vector<int>& candidates, int start) { 
        if (currSum > target || start >= candidates.size()) { 
            // Invalid solution
            return; 
        }
        
        if (currSum == target) { 
            res.push_back(currNums);
            return;  
        }

        for (int i=start; i<candidates.size(); i++) { 
            currNums.push_back(candidates[i]); 

            currSum += candidates[i]; 
            backtrack(currSum, currNums, target, candidates, i);

            currSum -= candidates[i]; 
            currNums.pop_back();
        }
    }



public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currNums; 
        backtrack(0, currNums, target, candidates, 0); 

        return res; 
    }
};