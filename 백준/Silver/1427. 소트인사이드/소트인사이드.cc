#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string strNum = to_string(N);
    sort(strNum.begin(), strNum.end(), greater<>());
    
    cout << strNum << endl;
    
    return 0;
}