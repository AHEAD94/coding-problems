#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int max_num = -1;
    int max_idx = -1;
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > max_num) {
            max_num = array[i];
            max_idx = i;
        }
    }
    answer.push_back(max_num);
    answer.push_back(max_idx);
    
    
    return answer;
}