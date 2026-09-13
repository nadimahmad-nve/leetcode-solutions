#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> except_self(n, 1); 

        for(int i=1; i<n; i++) {
            except_self[i] = except_self[i-1] * nums[i-1]; 
        }

        int current_suffix = 1; 
        for(int i=n-1; i>=0; i--) { 
            except_self[i] = except_self[i] * current_suffix;
            current_suffix = current_suffix * nums[i]; 
        }

        return except_self; 
    }
};