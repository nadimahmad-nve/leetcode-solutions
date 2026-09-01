#include <unordered_set>
#include <vector> 
using namespace std; 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> countNum; 

        for(int num: nums) { 
            if (countNum.count(num)) { 
                return true; 
            } else { 
                countNum.insert(num);  
            }
        }
        return false; 
    }
};