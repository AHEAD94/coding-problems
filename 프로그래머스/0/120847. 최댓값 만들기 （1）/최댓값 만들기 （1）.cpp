#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    answer = numbers[numbers.size()-1] * numbers[numbers.size()-2];
    
    return answer;
}