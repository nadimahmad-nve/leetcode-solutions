#include <vector>
#include <queue> 

using namespace std; 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        int rotted = 0;
        int total = 0; 
        int time = 0; 

        for (int i=0; i<m; i++) { 
            for (int j=0; j<n; j++) { 
                if (grid[i][j] == 2) { 
                    rotted++; 
                    total++; 
                    q.push({i, j}); 
                } else if (grid[i][j] == 1) { 
                    total++; 
                } 
            }
        }

        int dx[] = {-1, 1, 0, 0}; 
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) { 
            int currSize = q.size();
            bool hasSomethingRot;  

            hasSomethingRot = false; 

            for (int i=0; i<currSize; i++) { 
                pair<int, int> rottedCoords = q.front();
                q.pop(); 

                int x = rottedCoords.first; 
                int y = rottedCoords.second; 

                for (int k=0; k<4; k++) { 
                    int new_x = x + dx[k]; 
                    int new_y = y + dy[k]; 

                    if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n) { 
                        if (grid[new_x][new_y] == 1) { 
                            // Not rotted orange, it will be rotted now, so push
                            grid[new_x][new_y] = 2; 
                            q.push({new_x, new_y}); 
                            rotted++; 
                            hasSomethingRot = true; 
                        }
                    } 
                }
            }

            if (hasSomethingRot) time++; 
        }

        if (rotted == total) { 
            return time; 
        } else { 
            return -1; 
        }
    }
};