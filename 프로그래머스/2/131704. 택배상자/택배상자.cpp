#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int order_size = order.size();
    stack<int> sub_belt;
    
    int curr_box = 1; // 현재 컨베이어 벨트에서 접근할 상자의 번호
    
    for (int i = 0; i < order_size; i++) {
        while (order[i] > curr_box) {
            // 보조 벨트에 추가
            sub_belt.push(curr_box);
            curr_box++;
        }
        
        if (order[i] == curr_box) {
            // 현재 상자 순서가 일치하는 경우
            curr_box++;
            answer++;
        }
        else if (!sub_belt.empty() and sub_belt.top() == order[i]) {
            // 보조 벨트 최상위 박스 순서 확인
            sub_belt.pop();
            answer++;
        }
        else break; // 더이상 짐을 실을 수 없는 경우
    }
    
    return answer;
}