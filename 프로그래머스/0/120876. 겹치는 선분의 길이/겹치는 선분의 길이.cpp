#include <string>
#include <vector>

using namespace std;

vector<int> overlap(vector<int> line1, vector<int> line2) {    
    if (line1[0] <= line2[0]) {
        if (line1[1] <= line2[0]) return {};
        if (line2[1] <= line1[1]) return line2;
        if (line1[1] <= line2[1]) return {line2[0], line1[1]};
    }
    else {
        if (line2[1] <= line1[0]) return {};
        if (line1[1] <= line2[1]) return line1;
        if (line2[1] <= line1[1]) return {line1[0], line2[1]};
    }
    return {};
}

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<vector<int>> overlapped;
    
    // 서로 겹치는 선분들 overlapped에 저장하고 그 길이만큼 answer 증가
    for (int i = 0; i < lines.size() - 1; i++) {
        for (int j = i + 1; j < lines.size(); j++) {
            vector<int> temp_line;
            temp_line = overlap(lines[i], lines[j]);
            
            if (!temp_line.empty()) {
                overlapped.push_back(temp_line);
                answer += temp_line[1] - temp_line[0];
            }
        }
    }
    
    // overlapped가 2개 이상이면 answer가 중복으로 증가했으므로 overlapped끼리 겹치는 만큼 감소
    if (overlapped.size() >= 2) {
        for (int i = 0; i < overlapped.size() - 1; i++) {
            vector<int> temp_line;
            temp_line = overlap(overlapped[i], overlapped[i + 1]);

            if (!temp_line.empty()) 
                answer -= temp_line[1] - temp_line[0];
        }
    }
        
    return answer;
}