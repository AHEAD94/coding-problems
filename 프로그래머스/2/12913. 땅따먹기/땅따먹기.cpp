#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int land_size = land.size();
    
    for (int row = 1; row < land_size; row++) {
        for (int col = 0; col < 4; col++) {
            int max_num = 0;
            
            for (int upper_col = 0; upper_col < 4; upper_col++) {
                if (col != upper_col) {
                    int upper_val = land[row - 1][upper_col];
                    if (upper_val > max_num) max_num = upper_val;
                }
            }
            land[row][col] += max_num;
        }
    }
    
    for (int col = 0; col < 4; col++) {
        answer = max(answer, land[land_size - 1][col]);
    }
    
    return answer;
}