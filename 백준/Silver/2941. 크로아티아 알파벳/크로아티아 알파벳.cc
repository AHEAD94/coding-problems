#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;
    int answer = 0;
    
    vector<string> croatian = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    for (string c : croatian) {
        size_t idx;
        while ((idx = input.find(c)) != string::npos) {
            // 단순히 erase 하면, 서로 다른 두 문자가 합쳐져 새로운 크로아티아 알파벳이 될 수 있음
            input.replace(idx, c.size(), " ");
            answer++;
        }
    }
    answer += input.size() - count(input.begin(), input.end(), ' ');
    cout << answer << endl;
    return 0;
}