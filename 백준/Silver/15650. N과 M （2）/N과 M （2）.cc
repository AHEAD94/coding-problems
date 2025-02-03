#include <iostream>
#include <vector>

using namespace std;

void DFS(int N, int M, int start, vector<int>& result) {
    if (result.size() == M) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        result.push_back(i + 1);
        DFS(N, M, i + 1, result);
        result.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> result;
    DFS(N, M, 0, result);

    return 0;
}