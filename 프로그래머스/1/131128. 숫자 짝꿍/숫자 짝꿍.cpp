#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int x_len = X.length();
    int y_len = Y.length();
    unordered_map<char, int> nums_x(x_len);
    unordered_map<char, int> nums_y(y_len);
    unordered_map<char, int>::iterator iter_x;
    unordered_map<char, int>::iterator iter_y;
    priority_queue<char> comm_nums;
    
    for (int i = 0; i < x_len; i++) {
        nums_x[X[i]]++;
    }
    for (int i = 0; i < y_len; i++) {
        nums_y[Y[i]]++;
    }
    
    for (iter_x = nums_x.begin(); iter_x != nums_x.end(); iter_x++) {
        iter_y = nums_y.find(iter_x->first);
        if (iter_y != nums_y.end()) {
            int num_of_comms = min(iter_x->second, iter_y->second);
            for (int i = 0; i < num_of_comms; i++) {
                comm_nums.push(iter_x->first);
            }
        }
    }
    
    string st_biggest = "";
    while (!comm_nums.empty()) {
        st_biggest += comm_nums.top();
        comm_nums.pop();
    }
    
    if (st_biggest != "") answer = st_biggest;
    else answer = "-1";
    
    if (answer[0] == '0') answer = "0";
    
    return answer;
}