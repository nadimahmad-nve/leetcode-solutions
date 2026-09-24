#include <vector>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res; 

    void backtrack(int start, int n, int k, vector<int>& currentComb) { 
        if (currentComb.size() == k) { 
            res.push_back(currentComb); 
            return; 
        }

        for (int i=start; i<n+1; i++) {
            currentComb.push_back(i); 

            backtrack(i+1, n, k, currentComb); 

            currentComb.pop_back(); 
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> currentComb; 
        backtrack(1, n, k, currentComb);

        return res; 
    }
};