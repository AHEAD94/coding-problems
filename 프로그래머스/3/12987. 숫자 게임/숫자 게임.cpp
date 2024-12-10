#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int point = 0;
    
    size_t idx_a = 0;
    size_t idx_b = 0; 
    size_t size = B.size();
    
    while (idx_b < size) {
        if (A[idx_a] < B[idx_b]) {
            point++;
            idx_a++;
        }
        idx_b++;
    }
    answer = point;
        
    return answer;
}