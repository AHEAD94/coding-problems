#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) {
        int temp_size = commands[i][1] - commands[i][0] + 1;
        vector<int> temp(temp_size);
        
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], temp.begin());
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[commands[i][2] - 1]);
    }
    
    return answer;
}