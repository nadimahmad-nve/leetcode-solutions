#include <string>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false; 

        unordered_map<char, int> chars;

        for (char c : s) { 
            chars[c]++; 
        } 

        for (char c : t) { 
            chars[c]--; 
        }

        for (auto const& [key, val] : chars) { 
            if (val != 0) return false; 
        }
        
        return true; 
    }
};