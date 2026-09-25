#include <vector>

using namespace std; 

class Solution {
private: 
    void dfs(int i, int j, vector<vector<char>>& grid) { 
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols) { 
            return; 
        }

        if (grid[i][j] == '0') {
            // Water
            return; 
        }

        // We have found land. Flood it 
        grid[i][j] = '0'; 

        int dx[4] = {1, -1, 0, 0}; 
        int dy[4] = {0, 0, 1, -1}; 

        for (int k=0; k<4; k++) { 
            int new_i = i + dx[k]; 
            int new_j = j + dy[k]; 

            dfs(new_i, new_j, grid); 
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0; 

        for (int i=0; i<m; i++) { 
            for (int j=0; j<n; j++) { 
                if(grid[i][j] == '1') {
                    count++; 
                    dfs(i, j, grid); 
                }
            }
        }   

        return count; 
    }
};