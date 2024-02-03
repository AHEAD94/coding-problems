#include <string>
#include <vector>

using namespace std;

int pactorial(int i) {
    if (i >= 1) {
        return i * pactorial(i - 1);
    }
    else {
        return 1;
    }
}

int solution(int n) {
    int answer = 0;
    
    int num = 0;
    while (pactorial(num + 1) <= n) {
        num++;
    }
    
    answer = num;
    
    return answer;
}