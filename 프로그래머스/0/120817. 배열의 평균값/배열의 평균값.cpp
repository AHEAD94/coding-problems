#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    double sum = 0;
    for (int num : numbers)
        sum += num;
    
    answer = sum / numbers.size();
    
    return answer;
}