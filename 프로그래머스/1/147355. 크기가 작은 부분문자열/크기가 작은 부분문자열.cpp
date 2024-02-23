#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long p_num = stol(p);
    string token = "";
    
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        for (int j = 0; j < p.length(); j++) {
            token += t[i + j];  
        }
        if (stol(token) <= p_num) answer++;
        token = "";
    }
    
    return answer;
}