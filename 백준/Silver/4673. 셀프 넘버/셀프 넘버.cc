#include <iostream>
#include <vector>

using namespace std;

int GenerateNum(const int num) {
    int selfNum = num;
    
    string strNum = to_string(num);
    for (char c : strNum) {
        selfNum += c - '0';
    }
    
    return selfNum;
}

int main() {
    vector<int> selfNums(10001, 1);
    
    // 생성자가 있는 숫자들 제외
    for (int i = 1; i < 10001; i++) {
        int generated = GenerateNum(i);
        if (generated < 10001) {
            selfNums[generated] = 0;
        }
    }
    
    // 제외되지 않은 숫자들이 셀프 넘버
    for (int i = 1; i < 10001; i++) {
        if (selfNums[i] == 1) {
            cout << i << endl;
        }
    }
    
    return 0;
}