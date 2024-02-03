#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    
    string before_sorted = before;
    string after_sorted = after;
    
    sort(before_sorted.begin(), before_sorted.end());
    sort(after_sorted.begin(), after_sorted.end());
    
    if (before_sorted == after_sorted) {
        answer = 1;
    }
    
    return answer;
}