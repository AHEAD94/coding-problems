#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    for (int i = 0; i < goal.size(); i++) {
        int deck_number = 0;
        if (cards1.front() == goal[i]) deck_number = 1;
        if (cards2.front() == goal[i]) deck_number = 2;
        
        switch (deck_number) {
            case 1:
                cards1.erase(cards1.begin());
                break;
            case 2:
                cards2.erase(cards2.begin());
                break;
            default:
                answer = "No";
                break;
        }
        if (answer == "No") break;
    }
    
    if (answer != "No") answer = "Yes";
    
    return answer;
}