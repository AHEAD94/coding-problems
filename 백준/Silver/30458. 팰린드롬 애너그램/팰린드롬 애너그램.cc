//
//  main.cpp
//  temp
//
//  Created by Ryu Dae-ha on 4/14/24.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    cin >> str;
    
    string answer = "Yes";
    
    if (N % 2 == 1) {
        str.erase(str.begin() + N/2);
    }
    
    map<char, int> charCnt;
    
    for (char c : str) {
        charCnt[c]++;
    }
    
    for (auto it = charCnt.begin(); it != charCnt.end(); it++) {
        if (it->second % 2 == 1) {
            answer = "No";
            break;
        }
    }
                 
    cout << answer << endl;
    
    return 0;
}
