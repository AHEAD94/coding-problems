#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, x, y;
    cin >> N;
    
    vector<pair<int, int>> dots;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        dots.push_back(make_pair(x, y));
    }
    
    sort(dots.begin(), dots.end());
    
    for (auto d : dots) {
        cout << d.first << " " << d.second << '\n';
    }
    
    return 0;
}