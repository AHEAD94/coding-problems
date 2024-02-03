#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> temp_vect;
    
    for (int i = 0; i < num_list.size(); i++) {
        temp_vect.push_back(num_list[i]);
        
        if ((i+1) % n == 0) {
            answer.push_back(temp_vect);
            temp_vect.clear();
        }
    }
    
    return answer;
}