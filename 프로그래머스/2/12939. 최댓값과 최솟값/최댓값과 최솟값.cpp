#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream iss(s);
    string token = "";
    vector<int> tokens;
    
    while (getline(iss, token, ' ')) {
        tokens.push_back(stoi(token));
    }
    
    sort(tokens.begin(), tokens.end());
    
    answer += to_string(tokens[0]);
    answer += ' ';
    answer += to_string(tokens[tokens.size() - 1]);
    
    return answer;
}