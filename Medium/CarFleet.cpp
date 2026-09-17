#include <vector>
#include <algorithm> 

using namespace std; 

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        if (n == 1) return 1; 
        
        vector<pair<int, double>> t_and_s(n);

        for(int i = 0; i < n; i++) { 
            t_and_s[i] = {position[i], (double)(target - position[i]) / speed[i]}; 
        }

        sort(t_and_s.begin(), t_and_s.end()); 

        double maximum = t_and_s[n-1].second; 
        int fleets = 1; 

        for(int i = n-2; i >= 0; i--) { 
            if(t_and_s[i].second > maximum) { 
                fleets++; 
                maximum = t_and_s[i].second; 
            } 
        }

        return fleets; 
    }
};