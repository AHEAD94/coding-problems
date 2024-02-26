#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    const int NUM_OF_ALPHABET = 26;
    int shifting;
    
    if (n > NUM_OF_ALPHABET) shifting = n % NUM_OF_ALPHABET;
    else shifting = n;
    
    for (int i = 0; i < s.length(); i++) {
        if ('A' <= s[i] and s[i] <= 'Z') {
            if (s[i] + shifting > 'Z') {
                answer += ('A' - 1) + (s[i] + shifting - 'Z');
            }
            else answer += s[i] + shifting;
        }
        else if ('a' <= s[i] and s[i] <= 'z') {
            if (s[i] + shifting > 'z') {
                answer += ('a' - 1) + (s[i] + shifting - 'z');
            }
            else answer += s[i] + shifting;
        }
        else answer += s[i];
    }
    
    return answer;
}