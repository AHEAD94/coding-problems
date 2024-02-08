#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int denominator = a;
    int numerator = b;
    
    for (int i = 1; i <= denominator; i++) {
        if (denominator % i == 0 and numerator % i == 0) {
            denominator /= i;
            numerator /= i;
        }
    }
    
    answer = 1;
    
    for (int i = 2; i <= numerator; i++) {
        if (i % 2 != 0 and i % 5 != 0 and numerator % i == 0) {
            answer = 2;
        }
    }

    return answer;
}