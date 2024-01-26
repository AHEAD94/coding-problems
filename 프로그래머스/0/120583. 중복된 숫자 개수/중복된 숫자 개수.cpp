#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == n) {
            answer++;
        }
    }
    
    return answer;
}