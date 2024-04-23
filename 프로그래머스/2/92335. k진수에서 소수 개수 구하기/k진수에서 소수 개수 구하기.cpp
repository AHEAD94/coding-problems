#include <string>
#include <vector>
#include <cmath>

using namespace std;

string getKNaryNum(int number, int k) {
    string k_nary_num = "";
    
    while (number >= k) {
        k_nary_num.insert(k_nary_num.begin(), (number % k) + '0');
        
        number = number / k;
    }
    k_nary_num.insert(k_nary_num.begin(), (number % k) + '0');
    
    return k_nary_num;
}

bool isPrimeNum(long number) {
    bool is_prime = true;
    
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) is_prime = false;
    }
    if (number == 1) is_prime = false;
    
    return is_prime;
}

int solution(int n, int k) {
    int answer = -1;
    
    string k_nary_str = getKNaryNum(n, k);
    int k_nary_len = k_nary_str.length();
    
    vector<string> k_nary_nums;
    string token = "";
    
    for (int i = 0; i < k_nary_len; i++) {
        if (k_nary_str[i] != '0') {
            token += k_nary_str[i];
        }
        if (k_nary_str[i] == '0' or i >= k_nary_len - 1) {
            if (token != "" and isPrimeNum(stol(token))) {
                k_nary_nums.push_back(token);
            }
            token = "";
        }
    }
    
    answer = k_nary_nums.size();
    
    return answer;
}