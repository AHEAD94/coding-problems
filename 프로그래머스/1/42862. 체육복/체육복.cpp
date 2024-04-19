#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int victims = lost.size();
    int reserves = reserve.size();
    vector<bool> borrowed(victims, false);
    vector<bool> lent(reserves, false);
    
    answer += n - victims;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < victims; i++) {
        vector<int>::iterator iter = find(reserve.begin(), reserve.end(), lost[i]);
        
        if (iter != reserve.end()) {
            borrowed[i] = true;
            lent[iter - reserve.begin()] = true;
            answer++;
        }
    }
    
    for (int i = 0; i < victims; i++) {
        if (borrowed[i] == false) {
            for (int j = 0; j < reserves; j++) {
                if (lent[j] == false and abs(lost[i] - reserve[j]) <= 1) {
                    lent[j] = true;
                    borrowed[i] = true;
                    answer++;
                    break;
                }
            }
        }
    }
    
    return answer;
}