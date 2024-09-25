#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력 처리
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int good_nums = 0;
    
    // Two pointer 알고리즘을 사용하기 위해 정렬
    sort(A.begin(), A.end());
    
    // example: -15, -4, 5, 7, 12
    for (int i = 0; i < N; i++) {
        int cur_num = A[i];
        
        // Two pointer idx
        int l = 0;
        int r = N - 1;
        
        while (l < r) {
            if (l != i and r != i) {
                int sum = A[l] + A[r];
                
                if (sum == cur_num) {
                    good_nums++;
                    break;
                } else if (sum < cur_num) {
                    l++;
                } else if (sum > cur_num) {
                    r--;
                }
            } else if (l == i) {
                l++;
            } else if (r == i) {
                r--;
            }
        }
    }
    
    // 답안 출력
    cout << good_nums << endl;
}