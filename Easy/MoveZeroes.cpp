#include <vector>

using namespace std; 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 1) return; 

        int left = 0; 
        int right = 0; 

        while(right < n) { 
            if (nums[right] != 0) { 
                swap(nums[left], nums[right]);
                right++; 
                left++;  
            } else { 
                right++; 
            }
        }
    }
};