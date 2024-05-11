#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int matched = 0;
    int erased = 0;
    vector<int>::iterator iter;
    
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] != 0) {
            iter = find(win_nums.begin(), win_nums.end(), lottos[i]);
            if (iter != win_nums.end()) {
                matched++;
                win_nums.erase(iter);
            }
        }
        else erased++;
    }
    answer.push_back(min(7 - (matched + erased), 6));
    answer.push_back(min(7 - matched, 6));
    
    return answer;
}