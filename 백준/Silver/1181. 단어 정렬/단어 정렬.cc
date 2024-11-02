#include <iostream>
#include <set>

using namespace std;

struct CompByLen {
    bool operator()(const string& a, const string& b) const {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    cin >> N;
    
    set<string, CompByLen> str_set;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        str_set.insert(temp);
    }
    
    for (auto str : str_set) {
        cout << str << "\n";
    }
    
    return 0;
}