#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    int num1;
    int num2;
    int num3;
    char oper;
    char equal;
    
    for (int i = 0; i < quiz.size(); i++) {
        stringstream ss;
        ss.str(quiz[i]);
        ss >> num1 >> oper >> num2 >> equal >> num3;
        
        if (oper == '+') {
            if (num1 + num2 == num3) 
                answer.push_back("O");
            else answer.push_back("X");
        }
        else {
            if (num1 - num2 == num3)
                answer.push_back("O");
            else answer.push_back("X");
        }
    }
    
    return answer;
}