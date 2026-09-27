#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
private:
    bool dfs(int course, unordered_map<int, vector<int>>& adj, vector<int>& states) {
        if(states[course] == 1) { 
            return false; 
        }

        if(states[course] == 2) { 
            return true; 
        }

        states[course] = 1;

        for(int i=0; i<adj[course].size(); i++) { 
            if (!dfs(adj[course][i], adj, states)) {
                return false;
            } 
        }

        states[course] = 2; 
        return true;
    } 


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; 
        vector<int> states(numCourses, 0);
        // Build adjacency list 

        for(int i=0; i<prerequisites.size(); i++) { 
            vector<int> curr = prerequisites[i]; 
            adj[curr[1]].push_back(curr[0]); 
        }

        for (int i = 0; i < numCourses; i++) {
            if (states[i] == 0) {
                if (!dfs(i, adj, states)) {
                    return false; // A cycle was found somewhere in this branch
                }    
            }
        }

        return true; 
    }
};