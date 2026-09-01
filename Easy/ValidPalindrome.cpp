#include <string> 

using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {
        string new_s = ""; 

        for (int i=0; i<s.length(); i++) { 
            if (isalnum(s[i])) { 
                new_s += s[i]; 
            }
        }

        if (new_s.empty()) return true; 

        int left = 0; 
        int right = new_s.length() - 1; 

        while (left <= right) { 
            if (tolower(new_s[left]) == tolower(new_s[right])) { 
                left++; 
                right--; 
            } else { 
                return false; 
            }
        }  

        return true; 

    }
};