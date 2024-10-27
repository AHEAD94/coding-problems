#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {    
    int nums;
    cin >> nums;
    
    vector<int> num_vect(nums, 0);
    
    for (int i = 0; i < nums; i++) {
        cin >> num_vect[i];    
    }
    
    sort(num_vect.begin(), num_vect.end());
    
    for (int num : num_vect) {
        cout << num << "\n";
    }
    
    return 0;
}