#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] != 'a' and my_string[i] != 'e' and 
            my_string[i] != 'i' and my_string[i] != 'o' and
            my_string[i] != 'u')
        {
            answer += my_string[i];   
        }
    }
    
    return answer;
}