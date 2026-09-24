#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; 

    void backtrack(int start, int currSum, int target, vector<int>& candidates, vector<int>& currNums){
        if (currSum == target) { 
            res.push_back(currNums); 
            return; 
        }
        
        if (start >= candidates.size() || currSum > target) { 
            return; 
        }

        for (int i=start; i<candidates.size(); i++) { 
            if (i>start && candidates[i-1] == candidates[i]) {
                continue; 
                // Found a duplicate, move on
            }

            currNums.push_back(candidates[i]); 

            currSum += candidates[i]; 
            backtrack(i+1, currSum, target, candidates, currNums);

            currSum -= candidates[i]; 
            currNums.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currNums; 
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, candidates, currNums); 

        return res; 
    }
};