#include <string>
#include <vector>
#include <iostream>

using namespace std;

void PrintVector(const vector<vector<int>>& map) {
    for (auto iter1 = map.begin(); iter1 != map.end(); iter1++) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n, vector<int>(m, 1));

    for (auto puddle : puddles) {
        int row = puddle[1] - 1;
        int col = puddle[0] - 1;
        
        map[row][col] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 0) {
                // 맨 윗쪽 행 처리
                if (i == 0 and j != 0) {
                    map[i][j] = map[i][j - 1];
                }
                // 맨 왼쪽 열 처리
                if (i != 0 and j == 0) {
                    map[i][j] = map[i - 1][j];
                }
                // 그 외 경로 DP 계산
                if (i != 0 and j != 0) {
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
                    map[i][j] %= 1000000007;
                }
            }
        }
    }
    
    //PrintVector(map);
    
    answer = map.back().back();
    
    return answer;
}