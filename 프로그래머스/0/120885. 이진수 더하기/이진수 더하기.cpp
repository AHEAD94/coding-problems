#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int carry = 0;
    int added = 0;
    int len_diff = 0;
    
    string bin1_rev = bin1;
    string bin2_rev = bin2;
    reverse(bin1_rev.begin(), bin1_rev.end());
    reverse(bin2_rev.begin(), bin2_rev.end());
    
    if (bin1_rev.length() < bin2_rev.length()) {
        len_diff = bin2_rev.length() - bin1_rev.length();
        
        for (int i = 0; i < len_diff; i++) {
            bin1_rev += '0';
        }
    }
    else {
        len_diff = bin1_rev.length() - bin2_rev.length();
        
        for (int i = 0; i < len_diff; i++) {
            bin2_rev += '0';
        }
    }
    
    for (int i = 0; i < bin1_rev.length(); i++) {
        added = (bin1_rev[i] - '0') + (bin2_rev[i] - '0') + carry;
        
        if (added >= 2) {
            carry = 1;
            answer += added - 2 + '0';
        }
        else {
            answer += (bin1_rev[i] - '0') + (bin2_rev[i] - '0') + carry + '0';
            carry = 0;
        }
    }
    if (carry != 0) {
        answer += '1';
        carry = 0;
    }

    reverse(answer.begin(), answer.end());
         
    return answer;
}