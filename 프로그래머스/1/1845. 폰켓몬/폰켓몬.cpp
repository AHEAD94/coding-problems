#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> mon_num;
    
    for (int i = 0; i < nums.size(); i++) {
        mon_num[nums[i]]++;
    }
    
    for (pair<int, int> mon : mon_num) {
        answer++;
        if (answer >= nums.size() / 2) break;
    }
        
    return answer;
}