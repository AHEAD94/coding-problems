#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;

    vector<char> chars(C);
    for (int i = 0; i < C; i++) {
        cin >> chars[i];
    }

    vector<int> selection(C, 0);
    for (int i = 0; i < L; i++) {
        selection[i] = 1;
    }

    sort(chars.begin(), chars.end(), less<>());

    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    do {
        string combination = "";
        for (int i = 0; i < C; i++) {
            if (selection[i] == 1) {
                combination += chars[i];
            }
        }

        int vowel_num = 0;
        for (char v : vowels) {
            if (combination.find(v) != string::npos) {
                vowel_num++;
            }
        }
        int consonant_num = L - vowel_num;

        if (vowel_num >= 1 && consonant_num >= 2) {
            cout << combination << '\n';
        }
    } while (prev_permutation(selection.begin(), selection.end()));

    return 0;
}