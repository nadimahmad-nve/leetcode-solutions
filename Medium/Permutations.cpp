#include <vector>
#include <set> 

using namespace std; 

class Solution {
private:
    vector<vector<int>> res; 
    set<int> inCurr; 

    void backtrack(vector<int>& currNums, vector<int>& nums) { 
        if (currNums.size() == nums.size()) {
            res.push_back(currNums); 
            return; 
        }

        if (currNums.size() > nums.size()) { 
            return; 
            // Invalid. 
        }

        for(int i=0; i<nums.size(); i++) { 
            if (inCurr.count(nums[i])) { 
                // Already in set
                continue;
            }

            inCurr.insert(nums[i]);
            currNums.push_back(nums[i]);  
            backtrack(currNums, nums); 
            
            inCurr.erase(nums[i]); 
            currNums.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currNums;
        backtrack(currNums, nums); 

        return res; 
    }
};