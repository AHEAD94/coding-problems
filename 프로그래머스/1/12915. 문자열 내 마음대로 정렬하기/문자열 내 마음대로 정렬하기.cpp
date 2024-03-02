#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    priority_queue<pair<char, string>, vector<pair<char, string>>, greater<pair<char, string>>> pairs;
    
    for (int i = 0; i < strings.size(); i ++)
        pairs.push(make_pair(strings[i][n], strings[i]));
    
    while (!pairs.empty()) {
        answer.push_back(pairs.top().second);
        pairs.pop();
    }
    
    return answer;
}