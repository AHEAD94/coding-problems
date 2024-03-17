#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    unsigned long long answer = 1;
    
    int num1 = balls - share;
    int j = 1;
    if (num1 > share) {
        for (int i = num1 + 1; i <= balls; i++) {
            answer = answer * i;
            if (j <= num1) answer = answer / j;
            j++;
        }
    }
    else {
        for (int i = share + 1; i <= balls; i++) {
            answer = answer * i;
            if (j <= num1) answer = answer / j;
            j++;
        }
    }
    
    return answer;
}