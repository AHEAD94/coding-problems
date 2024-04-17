#include <string>
#include <vector>

using namespace std;

int getDifference(string a, string b) {
    int difference = 0;
    int st_len = a.length();
    
    for (int i = 0; i < st_len; i++) {
        if (a[i] != b[i]) difference++;
    }
    
    return difference;
}

void dfs(vector<bool> &visited, vector<string> &words, string next, string target, int depth, int &answer) {
    if (next == target) {
        answer = depth;
        return;
    }
    
    for (int i = 0; i < words.size(); i++) {
        if (getDifference(next, words[i]) == 1 and visited[i] == false) {
            visited[i] = true;
            dfs(visited, words, words[i], target, depth + 1, answer);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    
    dfs(visited, words, begin, target, 0, answer);
    
    return answer;
}