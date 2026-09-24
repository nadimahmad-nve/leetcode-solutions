#include <vector>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res; 
    vector<int> currentSubset; 

    void backtrack(int index, vector<int>& nums) {

        if (index >= nums.size()) {
            res.push_back(currentSubset);
            return;                       
        }

        currentSubset.push_back(nums[index]); // Choose
        backtrack(index + 1, nums);           // Explore
        
        // We must erase the number we just added 
        currentSubset.pop_back();             

        // Exclude the current number
        backtrack(index + 1, nums);       
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};