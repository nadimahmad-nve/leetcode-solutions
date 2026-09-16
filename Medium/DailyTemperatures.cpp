#include <vector> 
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s; 
        vector<int> result(temperatures.size(), 0);
        
        for (int i=0; i<temperatures.size(); i++) { 
            int currTemp = temperatures[i]; 

            while (!s.empty() && temperatures[s.top()] < currTemp) {
                int prev_index = s.top();
                result[prev_index] = i - prev_index; 
                s.pop(); 
            }
            s.push(i); 
        }

        return result; 
    }
};