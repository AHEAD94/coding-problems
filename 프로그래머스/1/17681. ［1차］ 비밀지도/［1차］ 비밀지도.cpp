#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string dec2bin_reverse(int dec) {
    string result = "";
    
    while (dec > 1) {
        result += (dec % 2) + '0';
        dec /= 2;
    }
    result += dec + '0';
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < arr1.size(); i++) {
        string bin1 = dec2bin_reverse(arr1[i]);
        string bin2 = dec2bin_reverse(arr2[i]);
        
        int len1 = bin1.length();
        int len2 = bin2.length();
        
        if (len1 < n) {
            for (int j = 0; j < n - len1; j++)
                bin1 += '0';
        }
        if (len2 < n) {
            for (int j = 0; j < n - len2; j++)
                bin2 += '0';
        }
        
        string row = "";
        for (int j = 0; j < n; j++) {
            if (bin1[j] == '1' or bin2[j] == '1') row += '#';
            else row += ' ';
        }
        reverse(row.begin(), row.end());
        answer.push_back(row);
    }
    
    return answer;
}