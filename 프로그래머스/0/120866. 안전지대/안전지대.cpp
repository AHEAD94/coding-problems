#include <string>
#include <vector>

using namespace std;

void setDangerArea(vector<vector<int>> &board, vector<vector<int>> dirs, int row, int col, int &safe_size) {
    int board_size = board.size();
    
    for (int dir = 0; dir < 8; dir++) {
        int next_row = row + dirs[dir][0];
        int next_col = col + dirs[dir][1];
        
        if (0 <= next_row and next_row < board_size and 0 <= next_col and next_col < board_size) {
            if (board[next_row][next_col] == 0) {
                board[next_row][next_col] = 2;
                safe_size--;
                if (safe_size <= 0) return;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int board_size = board.size();
    vector<vector<int>> directions = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };
    
    int safe_size = board_size * board_size;
    for (int row = 0; row < board_size; row++) {
        for (int col = 0; col < board_size; col++) {
            if (board[row][col] == 1) {
                safe_size--;
                if (safe_size <= 0) break;
                setDangerArea(board, directions, row, col, safe_size);
            }
        }
    }
    answer = safe_size;
    
    return answer;
}