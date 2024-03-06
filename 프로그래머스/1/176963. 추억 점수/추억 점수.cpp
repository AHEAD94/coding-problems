#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearning_map;
    
    for (int i = 0; i < name.size(); i++) {
        yearning_map.insert(make_pair(name[i], yearning[i]));
    }
    
    for (int i = 0; i < photo.size(); i++) {
        int yearning_point = 0;
        
        for (int j = 0; j < photo[i].size(); j++) {
            map<string, int>::iterator iter = yearning_map.find(photo[i][j]);
            if (iter != yearning_map.end()) {
                yearning_point += iter->second;
            }
        }
        
        answer.push_back(yearning_point);
    }
    
    return answer;
}