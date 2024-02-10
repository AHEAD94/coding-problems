#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int num;

int compare(int prev, int next) {
    bool ret;
    
    printf("--\n");
    printf("prev: %d\n", prev);
    printf("next: %d\n", next);
    
    if (abs(prev - num) == abs(next - num)) {
        ret = next < prev; // 차가 같다면 큰 값을 왼쪽으로
    }
    else {
        ret = abs(prev - num) < abs(next - num); // 차가 적으면 왼쪽으로
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