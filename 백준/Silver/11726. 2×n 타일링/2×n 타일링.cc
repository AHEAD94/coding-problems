#include <iostream>
#include <vector>

using namespace std;

/*
[1] (1)
|
[2] (2)
||
=
[3] (3)
|||
=|
|=
[4] (5)
||||
=||
|=|
||=
==
[5] (8)
|||||
=|||
|=||
||=|
|||=
==|
|==
=|=
*/

int main() {
    int n;
    cin >> n;

    vector<int> cases;
    cases.push_back(0);
    cases.push_back(1);
    cases.push_back(2);

    while (cases.size() <= n) {
        int dp_val = cases[cases.size() - 2] + cases[cases.size() - 1];
        cases.push_back(dp_val % 10007);
    }

    cout << cases[n] << endl;

    return 0;
}