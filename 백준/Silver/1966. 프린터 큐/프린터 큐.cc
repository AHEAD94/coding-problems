#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, P;
        cin >> N >> P;

        vector<pair<int, int>> printer_q(N);
        for (int j = 0; j < N; j++) {
            int priority;
            cin >> priority;
            printer_q[j] = make_pair(j, priority);
        }

        int printed_docs = 0;

        while (!printer_q.empty()) {
            auto front_doc = printer_q.front();
            int front_prior = front_doc.second;

            // 우선순위가 높은 문서가 있어도, 없어도 첫 항목 삭제
            printer_q.erase(printer_q.begin());

            // 우선순위가 높은 문서가 있을 경우 맨 뒤로 보냄
            bool higher_prior = false;
            for (auto doc : printer_q) {
                if (front_prior < doc.second) {
                    higher_prior = true;
                    printer_q.push_back(front_doc);
                    break;
                }
            }

            if (!higher_prior) {
                printed_docs++;
                // 출력 순서를 알고싶은 문서가 출력되면 멈춤
                if (front_doc.first == P) {
                    break;
                }
            }
        }

        cout << printed_docs << '\n';
    }

    return 0;
}