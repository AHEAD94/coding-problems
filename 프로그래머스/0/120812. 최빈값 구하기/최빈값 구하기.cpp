#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    vector<int> sorted = array;
    int answer = 0;
    int candidate = 0;
    int freq = 1;
    int max_freq = 0;
    
    sort(sorted.begin(), sorted.end());
    
    for (int i = 0; i < sorted.size(); i++) {
        if (sorted[i] == sorted[i + 1]) {
            freq++;        
        }
        else {
            if (freq > max_freq) {
                max_freq = freq;
                answer = sorted[i];
            }
            else if (freq == max_freq) {
                candidate = sorted[i];
            }
            freq = 1;
        }
    }
    
    if (candidate != 0 and answer < candidate) {
        answer = -1;
    }
    
    return answer;
}