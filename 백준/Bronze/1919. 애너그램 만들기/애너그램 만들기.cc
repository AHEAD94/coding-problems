#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    
    int answer = 0;
    
    const int alp_num = 26;
    vector<int> charCnt1(alp_num, 0);
    vector<int> charCnt2(alp_num, 0);
    
    for (char c : str1) {
        int idx = c - 'a';
        charCnt1[idx]++;
    }
    for (char c : str2) {
        int idx = c - 'a';
        charCnt2[idx]++;
    }
    
    for (int i = 0; i < alp_num; i++) {
        answer += abs(charCnt1[i] - charCnt2[i]);
    }
    
    cout << answer << endl;
    
    return 0;
}