#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string str_124 = "";
    int num = n;
    
    while (num > 0) {
        string str_num;
        if (num % 3 == 0) {
            str_num = to_string(4);
            num = num / 3 - 1;
        }
        else {
            str_num = to_string(num % 3);
            num = num / 3;
        }
        
        str_124.insert(0, str_num);
    }
    
    answer = str_124;
    
    return answer;
}