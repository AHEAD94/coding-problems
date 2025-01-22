#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> cases;
    cases.push_back(0);
    cases.push_back(1);
    cases.push_back(2);

    while (cases.size() <= n) {
        int size = cases.size();
        int dp_val = cases[size - 2] + cases[size - 1];
        cases.push_back(dp_val % 1000000007);
    }
    answer = cases[n];
    
    return answer;
}