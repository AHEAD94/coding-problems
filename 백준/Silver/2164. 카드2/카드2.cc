#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> cards;
    for (int i = 1; i <= N; i++) {
        cards.push(i);
    }
    
    bool erase_phase = true;
    while (cards.size() > 1) {        
        if (!erase_phase) {
            cards.push(cards.front());
            erase_phase = true;
        }
        else erase_phase = false;
            
        cards.pop();
    }
    
    cout << cards.front() << endl;
    
    return 0;
}