#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string base_3 = "";
    int temp = n;
    
    // 3진법 변환
    while (temp > 2) {
        base_3 += (temp % 3) + '0';
        temp /= 3;
    }
    base_3 += temp + '0';

    // 10진법 변환
    for (int i = 0; i < base_3.length(); i++) {
        answer += (base_3[base_3.length() - 1 - i] - '0') * pow(3, i);
    }
    
    return answer;
}