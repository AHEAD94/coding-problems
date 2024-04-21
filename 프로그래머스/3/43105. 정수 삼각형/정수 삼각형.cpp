#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int tri_size = triangle.size();
    vector<vector<int>> sum_tri(triangle.begin(), triangle.end());
    
    for (int level = 0; level < tri_size - 1; level++) {
        int num_size = triangle[level].size();
        
        for (int num_idx = 0; num_idx < num_size; num_idx++) {
            // 이전 인덱스의 우측 하단 계산값과 현재 인덱스의 좌측 하단 계산값 중 큰 값 선택
            int prev_left = sum_tri[level + 1][num_idx];
            int new_left = triangle[level + 1][num_idx] + sum_tri[level][num_idx];
            
            sum_tri[level + 1][num_idx] = max(prev_left, new_left);     // 좌 하단
            sum_tri[level + 1][num_idx + 1] += sum_tri[level][num_idx]; // 우 하단
        }
    }
    
    vector<int> bottom = sum_tri[tri_size - 1];
    answer = *max_element(bottom.begin(), bottom.end());
    
    return answer;
}