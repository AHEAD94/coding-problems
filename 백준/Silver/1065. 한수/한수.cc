#include <iostream>

using namespace std;

bool IsHansu(const int num) {
    // 1부터 99는 모두 한수
    if (1 <= num && num <= 99) {
        return true;
    }
    
    string str_num = to_string(num);
    size_t num_len = str_num.size();
    int diff = 0;
    
    for (size_t i = 0; i < num_len - 1; i++) {
        int curr_num = str_num.at(i) - '0';
        int next_num = str_num.at(i + 1) - '0';
        
        // 첫번째 수와 두번째 수의 차를 기준값으로 지정
        if (i == 0) diff = curr_num - next_num;
        
        // 각 자리의 차가 달라지면 한수가 아님
        if (curr_num - next_num != diff) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    int answer = 0;

    for (int num = 1; num <= N; num++) {
        if (IsHansu(num)) answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}