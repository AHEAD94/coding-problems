#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string binary = s;
    string no_zero = "";
    int str_len = 0;
    
    int num_of_convert = 0;
    int num_of_zero = 0;
    
    while (binary != "1") {
        // 문자열 내 0 제거
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] != '0') no_zero += binary[i];
            else num_of_zero++;
        }
        binary = "";
                
        // 문자열 길이를 2진법으로 표현
        str_len = no_zero.length();
        while (str_len > 1) {
            binary += (str_len % 2) + '0';
            str_len = str_len / 2;
        }
        binary += str_len + '0';
        reverse(binary.begin(), binary.end());
                
        num_of_convert++;
        
        // 변수 초기화
        no_zero = "";
        str_len = 0;
    }
    
    answer.push_back(num_of_convert);
    answer.push_back(num_of_zero);
    
    return answer;
}