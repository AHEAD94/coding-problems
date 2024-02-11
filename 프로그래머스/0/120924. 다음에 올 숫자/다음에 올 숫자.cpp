#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int common_diff = 0;
    int common_ratio = 0;
    int start_diff = common[1] - common[0];
    int start_ratio;
    
    if (common[0] != 0) start_ratio = common[1] / common[0];
    
    for (int i = 1; i < common.size(); i++) {
        if (i + 1 <= common.size() - 1) {
            if (common[i + 1] - common[i] == start_diff)
                common_diff = start_diff;
            if (common[i] != 0 and common[i + 1] / common[i] == start_ratio)
                common_ratio = start_ratio;
        }
    }
    
    if (common_diff == start_diff)
        answer = common[common.size() - 1] + common_diff;
    else if (common_ratio == start_ratio) 
        answer = common[common.size() - 1] * common_ratio;
    else answer = common[common.size() - 1] + start_diff;
    
    return answer;
}