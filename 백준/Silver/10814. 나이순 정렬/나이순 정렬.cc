#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, age;
    string name;
    cin >> N;
    
    vector<tuple<int, int, string>> people;
    
    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        people.push_back(make_tuple(i, age, name));
    }
    
    sort(people.begin(), people.end(), [](const tuple<int, int, string>& t1, const tuple<int, int, string>& t2) {
        if (get<1>(t1) == get<1>(t2))
            return get<0>(t1) < get<0>(t2);
        return get<1>(t1) < get<1>(t2);
    });
    
    for (auto p : people) {
        cout << get<1>(p) << " " << get<2>(p) << '\n';
    }
    
    return 0;
}