#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0;
    int idx2 = 0;
    
    for (int i = 0; i < goal.size(); i++) {
        if (cards1[idx1] == goal[i]) idx1++;
        else if (cards2[idx2] == goal[i]) idx2++;
        else {
            answer = "No";
            break;
        }
    }
    
    if (answer != "No") answer = "Yes";
    
    return answer;
}