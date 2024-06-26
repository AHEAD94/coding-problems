#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int curr_end = routes[0][1];
    for (auto route : routes) {
        if (curr_end < route[0]) {
            answer++;
            curr_end = route[1];
        }
        if (route[1] <= curr_end) curr_end = route[1];
    }
    answer++;
    
    return answer;
}