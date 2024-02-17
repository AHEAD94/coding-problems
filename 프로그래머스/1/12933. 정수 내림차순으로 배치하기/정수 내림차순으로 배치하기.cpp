#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string sorted = to_string(n);
    
    sort(sorted.begin(), sorted.end(), greater());
    
    answer = stod(sorted);
    
    return answer;
}