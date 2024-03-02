#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> foodStack;
    
    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += i + '0';
            foodStack.push(i);
        }
    }
    answer += '0';
    
    while (!foodStack.empty()) {
        answer += foodStack.top() + '0';
        foodStack.pop();
    }
    
    return answer;
}