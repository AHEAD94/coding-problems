#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    unordered_set<int> A;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << (A.find(num) != A.end()) << "\n";
    }
    
    return 0;
}