#include <vector>

using namespace std;

class Solution {
private:
    bool hasCycle(int course, vector<vector<int>>& adj, vector<int>& visited) { 
        if (visited[course] == 1) return true; 

        if(visited[course] == 2) return false; 

        visited[course] = 1;

        for (int neighbor : adj[course]) { 
            if (hasCycle(neighbor, adj, visited)) {
                return true; 
            }
        }

        visited[course] = 2; 

        return false; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        
        for (const auto& pair: prerequisites) { 
            int course = pair[0]; 
            int prereq = pair[1];

            adj[prereq].push_back(course);
        }

        vector<int> visited(numCourses, 0); 

        for (int i=0; i<numCourses; i++) { 
            if (visited[i] == 0) { 
                if (hasCycle(i, adj, visited)) { 
                    return false; 
                }
            }
        }

        return true; 
    }
};