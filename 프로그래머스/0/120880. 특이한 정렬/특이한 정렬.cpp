#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<int> templist = numlist;
    
    int front_min_diff = 10001;
    int rear_min_diff = 10001;
    int front_diff = 0;
    int rear_diff = 0;
    int front = 0;
    int rear;
    
    sort(templist.begin(), templist.end());
    
    while (answer.size() < numlist.size()) {
        rear = templist.size() - 1;
        
        front_diff = abs(n - templist[front]);
        rear_diff = abs(n - templist[rear]);
        
        if (front_diff < front_min_diff) {
            front_min_diff = front_diff;
        }
        if (rear_diff < rear_min_diff) {
            rear_min_diff = rear_diff;
        }
        
        if (front_min_diff > rear_min_diff) {
            answer.insert(answer.begin(), templist[front]);
            templist.erase(templist.begin());
        }
        else if (front_min_diff < rear_min_diff) {
            answer.insert(answer.begin(), templist[rear]);
            templist.erase(templist.end() - 1);
        }
        else {
            if (templist[front] == templist[rear]) {
                answer.insert(answer.begin(), templist[front]);
            }
            else {
                answer.insert(answer.begin(), min(templist[front], templist[rear]));
                answer.insert(answer.begin(), max(templist[front], templist[rear]));
                templist.erase(templist.begin());
                templist.erase(templist.end() - 1);
            }
        }
    }
    
    return answer;
}