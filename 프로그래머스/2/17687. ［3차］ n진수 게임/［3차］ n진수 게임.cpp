#include <string>
#include <vector>

using namespace std;

string transNumSys(int num, int num_sys) {
    string result = "";

    if (num == 0) return "0";
    
    while (num > 0) {
        int remainder = num % num_sys;
        char digit = remainder + '0';
        if (remainder >= 10) digit = 'A' + remainder - 10;
        result.insert(result.begin(), digit);
        num /= num_sys;
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int dec_num = -1;
    int curr_turn = 1;
    string num_str = "";
    
    while (t > 0) {
        if (num_str == "") num_str = transNumSys(++dec_num, n);
        char curr_digit = num_str.front();
        num_str.erase(num_str.begin());
        
        if (curr_turn == p) {
            answer += curr_digit;
            t--;
        }
        curr_turn++;
        if (curr_turn > m) curr_turn = 1;
    }
    
    return answer;
}