#include <string>
#include <vector>

using namespace std;

// (0, 0) (0, 1) (0, 2)
// (1, 0) (1, 1) (1, 2)
// (2, 0) (2, 1) (2, 2)

// 오른쪽 아래 방향의 대각선들은 row - col + (boardSize - 1) 값이 모두 동일해 인덱싱 가능
// 왼쪽 아래 방향의 대각선들은 row + col 값이 모두 동일해 인덱싱 가능

void DFS(vector<int>& cols, vector<int>& diag1, vector<int>& diag2, int& cases, const int row) {
    size_t boardSize = cols.size();
    
    if (row == boardSize) {
        cases++;
        return;
    }
    
    for (size_t col = 0; col < boardSize; col++) {
        if (!cols[col] && !diag1[row - col + (boardSize - 1)] && !diag2[row + col]) {
            cols[col] = 1;
            diag1[row - col + (boardSize - 1)] = 1;
            diag2[row + col] = 1;
            
            DFS(cols, diag1, diag2, cases, row + 1);
            
            cols[col] = 0;
            diag1[row - col + (boardSize - 1)] = 0;
            diag2[row + col] = 0;
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    // N x N 배열에서의 대각선 수
    const int diagNums = 2 * n - 1;
    
    vector<int> cols(n, 0);
    vector<int> rightDownDiags(diagNums, 0); // 오른쪽 아래 방향의 대각선 확인 벡터
    vector<int> leftDownDiags(diagNums, 0); // 왼쪽 아래 방향의 대각선 확인 벡터

    int cases = 0;
    DFS(cols, rightDownDiags, leftDownDiags, cases, 0);

    answer = cases;
        
    return answer;
}