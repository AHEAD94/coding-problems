#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    int min_diff = 101;
    int min_idx = 101;
    
    for (int i = 0; i < array.size(); i++) {
        if (abs(array[i] - n) == min_diff) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        
        if (abs(array[i] - n) < min_diff) {
            min_diff = abs(array[i] - n);
            min_idx = i;
        }
    }

    answer = array[min_idx];
    
    return answer;
}