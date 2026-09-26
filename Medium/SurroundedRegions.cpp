#include <vector>

using namespace std; 

class Solution {
private:

    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) { 
            return; 
            // Invalid indices 
        }

        if(board[i][j] == 'T' || board[i][j] == 'X') { 
            return; 
            // Already marked as safe OR cannot traverse (it's an X)
        }

        if(board[i][j] == 'O') { 
            // Found safe, mark it
            board[i][j] = 'T'; 
        }

        int dx[] = {1, -1, 0, 0}; 
        int dy[] = {0, 0, 1, -1}; 

        for(int k=0; k<4; k++) { 
            int new_x = i+dx[k]; 
            int new_y = j+dy[k]; 

            dfs(new_x, new_y, board); 
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(); 
        int cols = board[0].size(); 
        
        for (int i=0; i<cols; i++) { 
            dfs(0, i, board);
            dfs(rows-1, i, board); 
        }

        for (int i=0; i<rows; i++) { 
            dfs(i, 0, board);
            dfs(i, cols-1, board); 
        }

        for (int i=0; i<rows; i++) { 
            for (int j=0; j<cols; j++) {

                if (board[i][j] == 'T') { 
                    board[i][j] = 'O'; 
                } else if (board[i][j] == 'O') { 
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};