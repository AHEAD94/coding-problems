#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num_idx = 1;
    while (k > 0) {
        int first_num = number[num_idx - 1] - '0';
        int second_num = number[num_idx] - '0';
        
        if (first_num < second_num) {
            number.erase(number.begin() + num_idx - 1);
            k--;
            num_idx = 1;
        }
        else num_idx++;
        
        if (num_idx >= number.size()) {
            number.erase(number.end() - k, number.end());
            k = 0;
        }
    }
    
    answer = number;
    
    return answer;
}