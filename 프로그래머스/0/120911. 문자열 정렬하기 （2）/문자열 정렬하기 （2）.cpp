#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < my_string.length(); i++) {
        if ('A' <= my_string[i] and my_string[i] <= 'Z') {
            my_string[i] += 32; 
        }
    }
    
    sort(my_string.begin(), my_string.end());
    answer = my_string;
    
    return answer;
}