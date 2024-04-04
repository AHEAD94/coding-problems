#include <vector>
#include <iostream>

using namespace std;

bool is_prime(int num) {
    bool result = true;
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            result = false;
            break;
        }
    }
    
    return result;
}

int solution(vector<int> nums) {
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (is_prime(sum) == true) answer++;
            }
        }
    }

    return answer;
}