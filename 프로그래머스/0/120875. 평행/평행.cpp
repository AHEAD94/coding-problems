#include <string>
#include <vector>
#include <tuple>

using namespace std;

double GetSlope(vector<int> dot1, vector<int> dot2) {
    int dx = dot1[0] - dot2[0];
    int dy = dot1[1] - dot2[1];
    double slope = (double) dy / dx;
    
    return slope;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<tuple<vector<int>, vector<int>, double>> lines;

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            double slope = GetSlope(dots[i], dots[j]);
            lines.push_back({dots[i], dots[j], slope});
        }
    }
        
    int lines_size = lines.size();
    for (int i = 0; i < lines_size - 1; i++) {
        for (int j = i + 1; j < lines_size; j++) {
            if (get<2>(lines[i]) == get<2>(lines[j]) and
                get<0>(lines[i]) != get<0>(lines[j]) and
                get<0>(lines[i]) != get<1>(lines[j]) and
                get<1>(lines[i]) != get<0>(lines[j]) and
                get<1>(lines[i]) != get<1>(lines[j])) 
                answer = 1;
        }
    }
    
    return answer;
}