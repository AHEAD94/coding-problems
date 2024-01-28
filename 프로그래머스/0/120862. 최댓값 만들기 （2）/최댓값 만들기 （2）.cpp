#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    if (numbers[numbers.size()-1] * numbers[numbers.size()-2] > numbers[0] * numbers[1]) {
        answer = numbers[numbers.size()-1] * numbers[numbers.size()-2];
    }
    else {
        answer = numbers[0] * numbers[1];
    }
    
    return answer;
}