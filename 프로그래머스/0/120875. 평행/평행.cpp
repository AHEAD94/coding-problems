#include <string>
#include <vector>
#include <iostream>

using namespace std;

double GetSlope(vector<int> dot1, vector<int> dot2) {
    int dx = dot1[0] - dot2[0];
    int dy = dot1[1] - dot2[1];
    double slope = (double) dy / dx;
    
    return slope;
}

bool IsAllVisited(vector<bool> &visited) {   
    for (bool visit_info : visited) {
        if (visit_info == false) return false;
    }
    
    return true;
}

void DFS(vector<vector<int>> dots, vector<bool> &visited, vector<pair<vector<int>, vector<int>>> &lines, int &answer) {    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (!visited[i] and !visited[j]) {
                visited[i] = true;
                visited[j] = true;
                lines.push_back({dots[i], dots[j]});
                
                if (IsAllVisited(visited)) {
                    double slope1 = GetSlope(lines[0].first, lines[0].second);
                    double slope2 = GetSlope(lines[1].first, lines[1].second);
                    if (slope1 == slope2) {
                        answer = 1;
                        return;
                    }
                    else lines.clear();
                }
                
                DFS(dots, visited, lines, answer);
                visited[i] = false;
                visited[j] = false;
            }
        }
    }
    
    return;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<bool> visited(4, false);
    vector<pair<vector<int>, vector<int>>> lines;

    DFS(dots, visited, lines, answer);
    
    pair<vector<int>, vector<int>> line1;
    pair<vector<int>, vector<int>> line2;
    
    return answer;
}