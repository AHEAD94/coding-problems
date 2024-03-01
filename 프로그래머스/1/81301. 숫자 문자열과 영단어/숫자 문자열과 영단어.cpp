#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string stAnswer = "";
    string token = "";
    
    map<string, int> numMap;
    numMap.insert(make_pair("zero", 0));
    numMap.insert(make_pair("one", 1));
    numMap.insert(make_pair("two", 2));
    numMap.insert(make_pair("three", 3));
    numMap.insert(make_pair("four", 4));
    numMap.insert(make_pair("five", 5));
    numMap.insert(make_pair("six", 6));
    numMap.insert(make_pair("seven", 7));
    numMap.insert(make_pair("eight", 8));
    numMap.insert(make_pair("nine", 9));
    
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] and s[i] <= '9') stAnswer += s[i];
        else token += s[i];
        
        if (numMap.find(token) != numMap.end()) {
            stAnswer += to_string(numMap.find(token)->second);
            token = "";
        }
    }
    
    if (stAnswer != "") answer = stoi(stAnswer);
    
    return answer;
}