#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }
    
    // 작업시간을 줄이기 위한 정렬
    sort(times.begin(), times.end());
    
    int tot_min_time = 0;
    int acculmulated_time = 0;
    
    for (int time : times) {
        acculmulated_time += time;
        tot_min_time += acculmulated_time;
    }
    
    cout << tot_min_time << endl;
    
    return 0;
}