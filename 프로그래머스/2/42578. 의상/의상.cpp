#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clo_num;
    
    for (int i = 0; i < clothes.size(); i++) {
        clo_num[clothes[i][1]]++;
    }
    
    for (pair<string, int> clo : clo_num) {
        answer *= clo.second + 1; // 입지 않는 경우 포함
    }
    answer--; // 아무것도 입지 않는 경우 제외
    
    return answer;
}