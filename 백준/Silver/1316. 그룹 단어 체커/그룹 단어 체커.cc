#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int answer = 0;
    
    int N;
    cin >> N;
    
    vector<string> words(N, "");
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    for (string w : words) {
        set<char> checker;
        bool isGroupWord = true;
        
        // isGroupWord = true
        // 문자열 내 문자 순회:
        //     현재 문자가 이전 문자와 다른 경우:
        //         컨테이너에서 현재 문자 탐색
        //         탐색 결과가 있다면:
        //             isGroupWord = false
        //             BREAK
        //         현재 문자를 컨테이너에 기록
        // isGroupWord가 true라면:
        //     answer++
        
        // 두번째 문자부터 체크하므로, 첫 문자는 체커에 넣어두고 시작
        checker.insert(w[0]);
        
        int w_size = w.size();
        for (int i = 1; i < w_size; i++) {
            if (w[i] != w[i - 1]) {
                if (checker.find(w[i]) != checker.end()) {
                    isGroupWord = false;
                    break;
                }
                
                checker.insert(w[i]);
            }
        }
        
        if (isGroupWord == true) {
            answer++;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}