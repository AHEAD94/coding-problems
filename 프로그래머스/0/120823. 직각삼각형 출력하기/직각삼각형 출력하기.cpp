#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    //cout << n << endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}