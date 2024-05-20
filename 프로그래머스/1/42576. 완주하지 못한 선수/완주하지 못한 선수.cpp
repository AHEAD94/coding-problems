#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> completion_map(completion.size());
    int participant_size = participant.size();
    int completion_size = completion.size();
    
    for (int i = 0; i < completion_size; i++) {
        completion_map[completion[i]]++;
    }
    
    for (int i = 0; i < participant_size; i++) {
        string player = participant[i];
        if (completion_map[player] <= 0) {
            answer = player;
            break;
        }
        else completion_map[player]--;
    }
    
    return answer;
}