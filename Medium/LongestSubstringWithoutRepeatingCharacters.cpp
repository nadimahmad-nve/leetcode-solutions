#include <iostream>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
    
        int left = 0; 
        int result = 0; 

        for (int right=0; right<s.length(); right++) {
            char c_char = s[right]; 

            if (charMap.find(c_char) != charMap.end()) {
                left = max(left, charMap[c_char]+1); 
            }

            charMap[c_char] = right; 
            result = max(result, right-left+1); 
        }

        return result; 
    }
};