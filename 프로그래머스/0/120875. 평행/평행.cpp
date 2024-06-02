#include <string>
#include <vector>

using namespace std;

double GetSlope(vector<int> dot1, vector<int> dot2) {
    int dx = dot1[0] - dot2[0];
    int dy = dot1[1] - dot2[1];
    double slope = (double) dy / dx;
    
    return slope;
}

void DFS(vector<vector<int>> dots, vector<bool> &visited, vector<pair<vector<int>, vector<int>>> &lines) {    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (!visited[i] and !visited[j]) {
                visited[i] = true;
                visited[j] = true;
                
                lines.push_back({dots[i], dots[j]});
                DFS(dots, visited, lines);
                
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

    DFS(dots, visited, lines);
    
    pair<vector<int>, vector<int>> line1;
    pair<vector<int>, vector<int>> line2;
    
    int lines_size = lines.size();
    for (int i = 0; i < lines_size; i++) {
        if (i % 2 == 0) line1 = lines[i];
        else {
            line2 = lines[i];
            
            double slope1 = GetSlope(line1.first, line1.second);
            double slope2 = GetSlope(line2.first, line2.second);
            if (slope1 == slope2) {
                answer = 1;
                break;
            } 
        }
    }
        
    return answer;
}