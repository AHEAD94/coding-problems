#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> &numbers, int target, int depth, int temp_num, int &answer) {
    if (depth == numbers.size()) {
        if (temp_num == target) answer++;
        return;
    }
    
    DFS(numbers, target, depth + 1, temp_num - numbers[depth], answer);
    DFS(numbers, target, depth + 1, temp_num + numbers[depth], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, 0, 0, answer);
    
    return answer;
}