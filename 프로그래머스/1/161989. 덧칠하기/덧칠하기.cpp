#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int section_size = section.size();
    
    vector<int> walls(n, 1);
    
    for (int i = 0; i < section_size; i++) {
        int wall_idx = section[i] - 1;
        walls[wall_idx] = 0;
    }
    
    int wall_idx = 0;
    while (wall_idx < n) {
        if (walls[wall_idx] == 0) {
            answer++;
            wall_idx += m;
        }
        else wall_idx++;
    }
    
    return answer;
}