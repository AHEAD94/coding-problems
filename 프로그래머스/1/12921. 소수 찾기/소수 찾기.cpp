#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 0부터 n까지의 인덱스를 갖는 배열 선언
    vector<int> nums(n + 1, 1);
    nums[0] = 0;
    nums[1] = 0;
    
    // 기준 숫자 2부터 배수들을 0으로 변경
    for (int i = 2; i <= (int) sqrt(n); i++) {
        if (nums[i] == 1) {
            for (int j = 2; i * j <= n; j++) {
                nums[i * j] = 0;
            }
        }
    }

    // 배수들이 제거된 배열에서 값이 1인 인덱스들이 소수임
    for (int i = 0; i < n + 1; i++) {
        if (nums[i] == 1) answer++;
    }
    
    return answer;
}