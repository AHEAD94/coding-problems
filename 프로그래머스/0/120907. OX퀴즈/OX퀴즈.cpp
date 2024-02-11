#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    vector<string> tokens;
    string token = "";
    
    for (int i = 0; i < quiz.size(); i++) {
        for (int j = 0; j < quiz[i].length(); j++) {
            if (quiz[i][j] != ' ') 
                token += quiz[i][j];

            if (quiz[i][j] == ' ' or j >= quiz[i].length() - 1) {
                if (token != "") {
                    tokens.push_back(token);
                    token = "";
                }
            }
        }
        
        if (tokens[1] == "+") {
            if (stoi(tokens[0]) + stoi(tokens[2]) == stoi(tokens[4])) 
                answer.push_back("O");
            else answer.push_back("X");
        }
        else {
            if (stoi(tokens[0]) - stoi(tokens[2]) == stoi(tokens[4])) 
                answer.push_back("O");
            else answer.push_back("X");
        }
        
        tokens.clear();
    }
    
    return answer;
}