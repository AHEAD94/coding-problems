#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SortByDigit(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_nums;
    
    for (int num : numbers) {
        str_nums.push_back(to_string(num));
    }
    
    sort(str_nums.begin(), str_nums.end(), SortByDigit);
    
    for (string str_num : str_nums) {
        answer += str_num;
    }
    
    if (answer.front() == '0') answer = "0";
    
    return answer;
}