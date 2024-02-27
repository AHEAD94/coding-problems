#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_width = 0;
    int max_height = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        int temp_width = 0;
        int temp_height = 0;
        
        if (sizes[i][0] < sizes[i][1]) {
            temp_width = sizes[i][1];
            temp_height = sizes[i][0];
        }
        else {
            temp_width = sizes[i][0];
            temp_height = sizes[i][1];
        }
        
        if (temp_width > max_width) max_width = temp_width;
        if (temp_height > max_height) max_height = temp_height;
    }
    
    answer = max_width * max_height;
    
    return answer;
}