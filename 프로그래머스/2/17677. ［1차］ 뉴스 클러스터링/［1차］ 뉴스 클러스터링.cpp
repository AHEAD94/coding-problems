#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void parseString(string str, vector<string> &set_vect) {
    int str_len = str.length();
    
    for (int i = 0; i < str_len - 1; i++) {
        string token = "";
        
        for (int j = 0; j < 2; j++) {
            char temp_char = str[i + j];
        
            if ('a' <= temp_char and temp_char <= 'z') {
                temp_char += 'A' - 'a';
            }
            
            if ('A' <= temp_char and temp_char <= 'Z') {
                token += temp_char;
            }
            else {
                token = "";
            }
        }
        
        if (token.length() == 2) set_vect.push_back(token);
    }
}

int getJaccardSimilarity(vector<string> set1, vector<string> set2) {
    int jaccard_sim = 0;
    vector<string> intersections;
    vector<string> unions;
    
    for (string str : set1) {
        unions.push_back(str);
        
        vector<string>::iterator iter = find(set2.begin(), set2.end(), str);
        if (iter != set2.end()) {
            intersections.push_back(str);
            set2.erase(iter);
        }
    }
    
    for (string str : set2) {
        unions.push_back(str);
    }
    
    jaccard_sim = intersections.size() * 65536 / unions.size();
    
    return jaccard_sim;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> set1;
    vector<string> set2;
    
    parseString(str1, set1);
    parseString(str2, set2);
    
    if (set1.empty() and set2.empty()) 
        answer = 65536;
    else answer = getJaccardSimilarity(set1, set2);
    
    return answer;
}