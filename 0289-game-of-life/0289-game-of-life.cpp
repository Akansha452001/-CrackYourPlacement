class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
int n = board.size();
int m = board[0].size();
int r[8] = {1, 0, 0, -1, -1, -1, 1, 1}; // Row offsets for 8 neighbors
int c[8] = {0, -1, 1, 0, -1, 1, -1, 1}; // Column offsets for 8 neighbors
vector<vector<int>> ans(board.begin(), board.end());

for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        int count = 0; // Count of live neighbors
        for(int k = 0; k < 8; k++) { // Check all 8 directions
            int nr = i + r[k];
            int nc = j + c[k];
            // Check if neighbor is within bounds and is alive
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 1) {
                count++;
            }
        }
        // Apply Game of Life rules
        if(board[i][j] == 0) {
            if(count == 3) {
                ans[i][j] = 1; // Dead cell becomes alive
            }
        } else {
            if(count < 2 || count > 3) {
                ans[i][j] = 0; // Live cell dies
            }
        }
    }
}

board = ans; // Update the board with the new state

    }
};