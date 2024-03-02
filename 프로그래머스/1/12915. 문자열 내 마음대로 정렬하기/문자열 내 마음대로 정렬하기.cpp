#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Pair {
    char nth_char;
    string full_string;
};

bool arbitrary(Pair a, Pair b) {
    if (a.nth_char < b.nth_char) return true;
    else if (a.nth_char == b.nth_char) return a.full_string < b.full_string;
    else return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<Pair> pairs;
    
    for (int i = 0; i < strings.size(); i ++) {
        Pair newPair;
        newPair.nth_char = strings[i][n];
        newPair.full_string = strings[i];
        pairs.push_back(newPair);
    }
    
    sort(pairs.begin(), pairs.end(), arbitrary);
    
    for (int i = 0; i < pairs.size(); i++) {
        answer.push_back(pairs[i].full_string);
    }
    
    return answer;
}