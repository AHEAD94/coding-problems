#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    answer = ((2 * (k - 1)) % numbers.size()) + 1;
    
    return answer;
}