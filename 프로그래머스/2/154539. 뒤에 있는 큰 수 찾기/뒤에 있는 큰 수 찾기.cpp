#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int number_size = numbers.size();
    vector<int> answer(number_size, 0);
    stack<pair<int, int>> biggers;
    
    for (int i = 0; i < number_size; i++) {
        while (!biggers.empty() and biggers.top().second < numbers[i]) {
            answer[biggers.top().first] = numbers[i];
            biggers.pop();
        }
        biggers.push(make_pair(i, numbers[i]));
    }
    
    while (!biggers.empty()) {
        answer[biggers.top().first] = -1;
        biggers.pop();
    }
    
    return answer;
}