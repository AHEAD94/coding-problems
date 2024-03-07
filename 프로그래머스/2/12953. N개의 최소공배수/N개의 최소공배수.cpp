#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    int c = 0;
    
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

int solution(vector<int> arr) {
    int answer = 0;
    int lcm = (arr[0] * arr[1]) / GCD(arr[0], arr[1]);
    
    // a * b = GCD(a, b) * LCM(a, b);
    
    for (int i = 1; i < arr.size(); i++) {
        lcm = (lcm * arr[i]) / GCD(lcm, arr[i]);
    }
    
    answer = lcm;
    
    return answer;
}