#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int num = n;
    
    while (num >= a) {
        int rest = num % a;
        num = (num / a) * b;
        answer += num;        
        num += rest;
    }
    
    return answer;
}