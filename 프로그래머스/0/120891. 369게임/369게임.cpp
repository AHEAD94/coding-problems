#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    string stOrder = to_string(order);
    
    for (int i = 0; i < stOrder.length(); i++) {
        if (((stOrder[i] - 48) % 3 == 0) and ((stOrder[i] - 48) != 0)) {
            answer++;
        }
    }
    
    return answer;
}