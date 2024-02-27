#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) {
    string answer = "";
    string token = "";
    
    map<string, char> morse;
    morse.insert(make_pair(".-", 'a'));
    morse.insert(make_pair("-...", 'b'));
    morse.insert(make_pair("-.-.", 'c'));
    morse.insert(make_pair("-..", 'd'));
    morse.insert(make_pair(".", 'e'));
    morse.insert(make_pair("..-.", 'f'));
    morse.insert(make_pair("--.", 'g'));
    morse.insert(make_pair("....", 'h'));
    morse.insert(make_pair("..", 'i'));
    morse.insert(make_pair(".---", 'j'));
    morse.insert(make_pair("-.-", 'k'));
    morse.insert(make_pair(".-..", 'l'));
    morse.insert(make_pair("--", 'm'));
    morse.insert(make_pair("-.", 'n'));
    morse.insert(make_pair("---", 'o'));
    morse.insert(make_pair(".--.", 'p'));
    morse.insert(make_pair("--.-", 'q'));
    morse.insert(make_pair(".-.", 'r'));
    morse.insert(make_pair("...", 's'));
    morse.insert(make_pair("-", 't'));
    morse.insert(make_pair("..-", 'u'));
    morse.insert(make_pair("...-", 'v'));
    morse.insert(make_pair(".--", 'w'));
    morse.insert(make_pair("-..-", 'x'));
    morse.insert(make_pair("-.--", 'y'));
    morse.insert(make_pair("--..", 'z'));
    
    for (int i = 0; i < letter.length(); i++) {
        if (letter[i] != ' ') token += letter[i];
        
        if (letter[i] == ' ' or i == letter.length() - 1) {
            answer += morse.find(token)->second;
            token = "";
        }
    }
    
    return answer;
}