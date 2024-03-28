#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> mon_set;
    
    for (int i = 0; i < nums.size(); i++) {
        mon_set.insert(nums[i]);
    }
    
    answer = min(nums.size() / 2, mon_set.size());
    
    return answer;
}