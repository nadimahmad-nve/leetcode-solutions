#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); 
        int maxLength = 1; 
        int start = 0; 
        vector<vector<bool>> grid(n, vector<bool>(n, false));

        for(int i=0; i<=n-1; i++) { 
            grid[i][i] = true;
            maxLength = 1;  
        } 

        for(int i=0; i<n-1; i++) { 
            if (s[i] == s[i+1]) { 
                grid[i][i+1] = true;
                maxLength = 2;
                start = i;  
            }
        }

        for(int length=3; length<=n; length++) { 
            for (int i=0; i <= n-length; i++) { 
                int j = i + length - 1; 

                if (s[i] == s[j] && grid[i+1][j-1] == true) { 
                    grid[i][j] = true; 
                    start = i;
                    maxLength = length; 
                }
            }
        }

        return s.substr(start, maxLength); 
    }
};