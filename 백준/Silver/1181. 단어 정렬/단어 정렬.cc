#include <iostream>
#include <set>

using namespace std;

// set 의 정렬 기준을 바꾸기 위한 구조체 Compare 정의
struct Compare {
	bool operator() (const string &a, const string &b) const{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int N;
	set<string, Compare> sets; // 이와 같이 선언
	cin >> N;
	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		sets.insert(temp);
	}

	for (auto str : sets) {
		cout << str << '\n';
	}

	return 0;
}