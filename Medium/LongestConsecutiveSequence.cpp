#include <vector>
#include <unordered_set>

using namespace std; 

class Solution {
private:
    int countConsecs(int num, const unordered_set<int>& num_set) {
        int current_length = 1; 

        while (num_set.count(num + 1) != 0) {
            current_length++; 
            num += 1; 
        }

        return current_length; 
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_sequence = 0; 

        for (const int& num : num_set) {
            if (num_set.count(num - 1) == 0) {
                int seq = countConsecs(num, num_set);

                if (seq > longest_sequence) {
                    longest_sequence = seq; 
                }
            }
        }

        return longest_sequence; 
    }
};