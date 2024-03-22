#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    const int CONSEQUTIVE_DAYS = 10;
    vector<string> item(want.begin(), want.end());
    vector<int> remain(number.begin(), number.end());
        
    for (int i = 0; i < discount.size(); i++) {
        for (int j = i; j < i + CONSEQUTIVE_DAYS; j++) {
            vector<string>::iterator iter = find(item.begin(), item.end(), discount[j]);
            
            if (iter != item.end()) { // 리스트에 있는 물품일 때
                int idx = iter - item.begin();
                remain[idx]--;
                
                if (remain[idx] == 0) {
                    item.erase(item.begin() + idx);
                    remain.erase(remain.begin() + idx);
                }
            }
            else break;
        }
        
        if (remain.empty()) answer++;
        
        remain = number;
        item = want;
    }
    
    return answer;
}