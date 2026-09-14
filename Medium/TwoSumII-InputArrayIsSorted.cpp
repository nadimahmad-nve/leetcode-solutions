#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0; 
        int high = n-1; 
        int curr_sum = numbers[low] + numbers[high]; 

        while (curr_sum != target) { 
            if (curr_sum > target) { 
                curr_sum -= numbers[high]; 
                high = high-1; 
                curr_sum += numbers[high];  
            } else if (curr_sum < target) { 
                curr_sum -= numbers[low]; 
                low = low+1; 
                curr_sum += numbers[low]; 
            } 
        }

        return vector<int> {low+1, high+1};
    }
};