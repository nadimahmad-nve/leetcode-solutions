#include <vector> 

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size(); 

       int low = 0; 
       int high = n-1;
       int mid; 

       while(low <= high) { 
        mid = low + (high-low)/2;
        
        if (nums[mid] == target) {
            return mid; 
        }

        // Which side of the array are we in? 
        
        // Left side (sorted)
        if (nums[mid] >= nums[low]) { 
            if (nums[low] <= target && nums[mid] > target) { 
               // Target is in left side 
               high = mid-1; 
            } else { 
               // Target is in right side 
               low = mid+1;  
            }
        } else if (nums[mid] < nums[low]) { 
            // Right Side 
            if (nums[mid] < target && nums[high] >= target) { 
                // Target is in right side
                low = mid+1; 
            } else { 
                // Target is in left side
                high = mid-1; 
            }
        }

       } 

       return -1; 
    }
};