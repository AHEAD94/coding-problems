#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    string stNum = "";
    
    for (int i = 0; i < array.size(); i++) {
        stNum = to_string(array[i]);
        
        for (int j = 0; j < stNum.length(); j++) {
            if (stNum[j] == 7 + '0') {
                answer++;
            }
        }
    }
    
    return answer;
}