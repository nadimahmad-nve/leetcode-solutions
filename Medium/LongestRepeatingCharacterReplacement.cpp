#include <vector> 
#include <unordered_map>
#include <string>

using namespace std; 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        
        int res = 0; 
        int left = 0; 
        int max_freq = 0; // Only tracks the historical maximum count

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            max_freq = max(max_freq, freq[s[right]]); 


            if ((right - left + 1) - max_freq > k) {
                freq[s[left]]--; 
                left++; 
            }

            res = max(res, right - left + 1); 
        }

        return res; 
    }
};