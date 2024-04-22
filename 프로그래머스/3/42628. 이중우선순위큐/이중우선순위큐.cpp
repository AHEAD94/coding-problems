#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int op_size = operations.size();
    vector<int> op_vect;
    
    for (int i = 0; i < op_size; i++) {
        string op_str = operations[i];
        char op_char = op_str[0];
        
        op_str.erase(op_str.begin(), op_str.begin() + 2);
        int number = stoi(op_str);
        
        if (op_char == 'I') op_vect.push_back(number);
        if (op_char == 'D') {
            if (!op_vect.empty()) {
                if (number == 1) op_vect.erase(op_vect.end() - 1);
                else op_vect.erase(op_vect.begin());
            }
        }
        sort(op_vect.begin(), op_vect.end());
    }
    
    if (op_vect.empty()) answer = {0, 0};
    else answer = {op_vect.back(), op_vect.front()};
        
    return answer;
}