#include <string>
#include <vector>

using namespace std;

int getNumOfOne(int number) {
    int num_of_1 = 0;
    int temp = number;
    
    while (temp > 1) {
        if (temp % 2 == 1) num_of_1++;
        temp /= 2;
    }
    
    return num_of_1;
}

int solution(int n) {
    int answer = 0;
    int next_num = n + 1;
    
    while (next_num <= 1000000) {
        if (getNumOfOne(n) == getNumOfOne(next_num)) {
            answer = next_num;
            break;
        }
        else next_num++;
    }
    
    return answer;
}