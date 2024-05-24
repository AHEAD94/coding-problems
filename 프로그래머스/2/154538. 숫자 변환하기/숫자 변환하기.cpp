#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(int x, int y, int n) {
    int calc_num = 0;
    bool is_answer_found = false;

    queue<pair<int, int>> num_q;
    num_q.push(make_pair(y, 0));

    while (!num_q.empty()) {
        int num = num_q.front().first;
        calc_num = num_q.front().second;
        num_q.pop();

        if (num == x) {
            is_answer_found = true;
            break;
        }

        if (num % 3 == 0 and num / 3 >= x)
            num_q.push(make_pair(num / 3, calc_num + 1));
        if (num % 2 == 0 and num / 2 >= x)
            num_q.push(make_pair(num / 2, calc_num + 1));
        if (num - n >= x) 
            num_q.push(make_pair(num - n, calc_num + 1));
    }

    if (is_answer_found == false) calc_num = -1;

    return calc_num;
}

int solution(int x, int y, int n) {
    int answer = 0;

    answer = BFS(x, y ,n);

    return answer;
}