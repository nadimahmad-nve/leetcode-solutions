#include <vector>

using namespace std; 

class Solution {
private: 
    void dfs(vector<vector<char>>& grid, int r, int c) { 
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        if (r < 0 || c < 0 || r >= rows || c >= cols) { 
            return;
        }

        if (grid[r][c] == '0') return; 

        grid[r][c] = '0'; 

        int dx[4] = {1, -1, 0, 0}; 
        int dy[4] = {0, 0, 1, -1}; 

        for (int k=0; k<4; k++) { 
            int new_x = r + dx[k];
            int new_y = c + dy[k];

            dfs(grid, new_x, new_y);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        int count = 0;

        for(int i=0; i<m; i++) { 
            for(int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    count++; 
                    dfs(grid, i, j);
                }
            }
        } 

        return count; 
    }
};