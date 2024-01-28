#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for (int i = 0; i < rsp.length(); i++) {
        switch (rsp[i]) {
            case '0':
                answer += '5';
                break;
            case '2':
                answer += '0';
                break;
            case '5':
                answer += '2';
                break;
            default:
                break;
        }
    }
    
    return answer;
}