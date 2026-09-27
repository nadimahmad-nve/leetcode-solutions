#include <vector>

using namespace std; 

class Solution {
private:
    int timeline(int start, int end, vector<int>& nums) { 
        int twoBack = 0; 
        int oneBack = 0; 

        for (int i = start; i <= end; i++) { 
            int current = max(nums[i] + twoBack, oneBack);
            twoBack = oneBack;
            oneBack = current;
        }

        return oneBack;
    }


public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size(); 
        int A = timeline(0, n-2, nums); 
        int B = timeline(1, n-1, nums); 

        return max(A,B); 
    }
};