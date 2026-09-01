#include <vector>
#include <string> 
#include <unordered_map>
#include <algorithm>

using namespace std; 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs) { 
            string sorted_s = s; 
            sort(sorted_s.begin(), sorted_s.end());
            anagramGroups[sorted_s].push_back(s);  
        }

        vector<vector<string>> result; 

        for (auto& pair : anagramGroups) { 
            result.push_back(pair.second); 
        }

        return result; 
    }
};