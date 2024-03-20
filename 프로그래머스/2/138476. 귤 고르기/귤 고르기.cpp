#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool byValue(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

// map을 이용해 크기에 따른 귤 개수를 매핑하고
// vector에 옮겨서 value 기준 정렬한 뒤    
// 박스에 담을 귤 수 차감

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> size_n_num;
    
    for (int i = 0; i < tangerine.size(); i++) {
        map<int, int>::iterator iter = size_n_num.find(tangerine[i]);
        
        if (iter == size_n_num.end())
            size_n_num.insert(make_pair(tangerine[i], 1));
        else iter->second++;
    }
    
    vector<pair<int, int>> sorting_vec(size_n_num.begin(), size_n_num.end());
    sort(sorting_vec.begin(), sorting_vec.end(), byValue);
        
    for (int i = 0; i < sorting_vec.size(); i++) {
        if (k > 0) {
            k -= sorting_vec[i].second;
            answer++;
        }        
        else break;
    }
    
    return answer;
}