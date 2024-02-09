#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    string token = "";
    int posX = string::npos;
    int numOfX = 0;
    int numOfConst = 0;
    
    for (int i = 0; i < polynomial.length(); i++) {
        if (('0' <= polynomial[i] and polynomial[i] <= '9') or polynomial[i] == 'x') {
            token += polynomial[i];
        }
        
        if (polynomial[i] == ' ' or polynomial[i] == '+' or i >= polynomial.length() - 1) {
            posX = token.find('x');
            
            if (posX != string::npos) { // x
                if (posX == 0) {
                    numOfX++;
                }
                else {
                    token = token.substr(0, posX);
                    if (token != "") numOfX += stoi(token);
                }
            }
            else { // constant
                if (token != "") numOfConst += stoi(token);
            }
            token = "";
        }
    }
    
    if (numOfX != 0) {
        if (numOfX != 1) {
            answer += to_string(numOfX);
        }
        answer += "x";
        
        if (numOfConst != 0) {
            answer += " + ";
        }
    }
    if (numOfConst != 0) {
        answer += to_string(numOfConst);
    }
    
    return answer;
}