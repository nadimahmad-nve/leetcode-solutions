#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> current; 

        backtrack(candidates, 0, current, result, target);

        return result; 
    }

private:
    void backtrack(vector<int>& candidates, int index, vector<int>& current, vector<vector<int>>& result, int target) { 
        if (target == 0) { 
            result.push_back(current); 
            return; 
        }

        if (target < 0 || index == candidates.size()) { 
            return;
        }

        current.push_back(candidates[index]); 
        backtrack(candidates, index, current, result, target-candidates[index]); 

        current.pop_back();

        backtrack(candidates, index+1, current, result, target); 
    }
};