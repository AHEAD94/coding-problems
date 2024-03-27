#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // 12[3 223] 333
    // 1234 223[4 3334 444]4
    
    for (long long i = left; i <= right; i++) {
        long long row_idx = i / n;
        long long col_idx = i % n;
        
        if (row_idx < col_idx)
            answer.push_back(col_idx + 1);
        else answer.push_back(row_idx + 1);
    }
    
    return answer;
}