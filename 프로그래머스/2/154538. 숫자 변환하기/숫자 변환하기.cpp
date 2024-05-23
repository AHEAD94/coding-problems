#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0; // 이미 같은 수이면 연산이 필요하지 않음

    queue<pair<int, int>> q; // pair<현재 수, 연산 횟수>
    unordered_set<int> visited; // 방문한 수를 기록

    q.push({x, 0}); // 초기값 삽입
    visited.insert(x); // 방문한 수로 체크

    while (!q.empty()) {
        int cur_num = q.front().first;
        int operations = q.front().second;
        q.pop();

        if (cur_num == y) return operations; // 목표 수에 도달했을 때

        // 가능한 연산 수행 후 큐에 삽입
        int add_n = cur_num + n;
        int mul_2 = cur_num * 2;
        int mul_3 = cur_num * 3;

        if (add_n <= y && visited.find(add_n) == visited.end()) {
            q.push({add_n, operations + 1});
            visited.insert(add_n);
        }
        if (mul_2 <= y && visited.find(mul_2) == visited.end()) {
            q.push({mul_2, operations + 1});
            visited.insert(mul_2);
        }
        if (mul_3 <= y && visited.find(mul_3) == visited.end()) {
            q.push({mul_3, operations + 1});
            visited.insert(mul_3);
        }
    }

    return -1; // 목표 수에 도달할 수 없는 경우
}

int main() {
    int x = 2;
    int y = 162;
    int n = 3;

    cout << "Minimum operations required: " << solution(x, y, n) << endl;

    return 0;
}