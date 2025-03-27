#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_container(const T& cont) {
	for (auto iter = cont.begin(); iter != cont.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	sort(values.begin(), values.end());

	vector<int> cases(k + 1, 0);
	cases[0] = 1;

	for (auto iter = values.begin(); iter != values.end(); iter++) {
		for (int val = (*iter); val <= k; val++) {
			cases[val] += cases[val - (*iter)];
		}

		// print_container(cases);
	}

	cout << cases[k] << endl;

	return 0;
}