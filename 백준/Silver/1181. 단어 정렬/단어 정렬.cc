#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool ByLen(const string a, const string b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {
    int N;
    cin >> N;
    
    set<string> str_set;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        str_set.insert(temp);
    }
    
    vector<string> str_vec(str_set.size(), "");
    copy(str_set.begin(), str_set.end(), str_vec.begin());
    sort(str_vec.begin(), str_vec.end(), ByLen);
    
    for (auto str : str_vec) cout << str << endl;
}