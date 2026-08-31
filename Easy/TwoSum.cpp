#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap; 

        for(int i=0; i<nums.size(); i++) { 
            int currentNumber = nums[i]; 
            int differenceNeeded = target - currentNumber; 

            if (prevMap.find(differenceNeeded) != prevMap.end()) {
                return {prevMap[differenceNeeded], i}; 
            } else { 
                prevMap[currentNumber] = i; 
            }
        }
        return {}; 
    }
};