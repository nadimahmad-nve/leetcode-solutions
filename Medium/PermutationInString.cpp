#include <vector>
#include <string>

using namespace std; 

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) { 
            return false; 
        }

        vector<int> s1map(26, 0); 
        vector<int> s2map(26, 0); 

        int n = s1.length(); 

        for (int i=0; i<n; i++) {
            char c = s1[i];  
            s1map[c - 'a']++;

            char cx = s2[i];
            s2map[cx - 'a']++; 
        }

        int left = 0; 
        int right = n-1; 

        while(right < s2.length()) { 
            if (s1map == s2map) return true;
            if (right == (s2.length())-1) return false;  

            s2map[s2[left] - 'a']--; 
            left++; 

            right++;
            s2map[s2[right] - 'a']++; 
        }

        return false; 
    }
};