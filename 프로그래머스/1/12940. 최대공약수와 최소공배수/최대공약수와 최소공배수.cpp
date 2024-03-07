#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    int c;
    
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = GCD(n, m);
    int lcm = (n * m) / gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
        
    return answer;
}