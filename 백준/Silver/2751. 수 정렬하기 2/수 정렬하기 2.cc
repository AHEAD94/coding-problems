#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    set<int> num_set;
    
    int nums;
    cin >> nums;
    
    for (int i = 0; i < nums; i++) {
        int num;
        cin >> num;    
        num_set.insert(num);
    }
    
    vector<int> num_vect(num_set.size());
    copy(num_set.begin(), num_set.end(), num_vect.begin());
    sort(num_vect.begin(), num_vect.end());
    
    for (int num : num_vect) {
        cout << num << "\n";
    }
    
    return 0;
}