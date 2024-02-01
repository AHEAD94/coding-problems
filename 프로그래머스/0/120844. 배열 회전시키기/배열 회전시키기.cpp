#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    
    answer = numbers;
    int temp;
    
    if (direction == "right") {
        temp = numbers[numbers.size()-1];
        answer.erase(answer.end()-1);
        answer.insert(answer.begin(), temp);
    }
    else {
        temp = numbers[0];
        answer.erase(answer.begin());
        answer.insert(answer.end(), temp);
    }
    
    return answer;
}