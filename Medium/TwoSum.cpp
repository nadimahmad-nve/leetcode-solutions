#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> possibilities; 

        for(int i=0; i<n-2; i++) { 
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int fixed_num = nums[i];

            // Two Sum
            int left = i+1; 
            int right = n-1;

            while (left < right) {
                int curr_sum = fixed_num + nums[left] + nums[right]; 

                if (curr_sum == 0) {
                    possibilities.push_back({fixed_num, nums[left], nums[right]}); 
                    right--;
                    left++; 

                    while ((nums[left] == nums[left - 1]) && (left < right)) {
                        left++; 
                    }
                }

                if(curr_sum > 0) { 
                    right--; 
                } else if (curr_sum < 0) { 
                    left++; 
                }
            }
        }

        return possibilities; 
    }
};