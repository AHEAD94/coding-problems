#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int num = 2;
    
    int numer3 = (numer1 * denom2) + (numer2 * denom1);
    int denom3 = denom1 * denom2;

    while (num <= denom3) {
        if (numer3 % num == 0 and denom3 % num == 0) {
            numer3 /= num;
            denom3 /= num;
        }
        else num++;
    }
    
    answer.push_back(numer3);
    answer.push_back(denom3);
    
    return answer;
}