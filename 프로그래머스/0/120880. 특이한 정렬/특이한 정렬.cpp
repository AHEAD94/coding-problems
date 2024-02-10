#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int num;

int compare(int prev, int next) {
    bool ret;
    
    if (abs(prev - num) == abs(next - num)) {
        ret = next < prev;
    }
    else {
        ret = abs(prev - num) < abs(next - num);
    }
    
    return ret;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<int> templist = numlist;
    
    num = n;
    
    sort(templist.begin(), templist.end(), compare);
    
    answer = templist;
    
    return answer;
}