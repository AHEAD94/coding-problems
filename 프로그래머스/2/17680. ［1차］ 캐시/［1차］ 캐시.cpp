#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool byValue(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> cache;
    map<string, int>::iterator iter;
    
    for (string city : cities) {
        bool cache_miss = false;
        string upper_city = "";
        
        // 도시 이름 대문자로 통일
        for (int i = 0; i < city.length(); i++) {
            upper_city += toupper(city[i]);
        }
        
        // 실행시간 반영
        iter = cache.find(upper_city);
        if (iter == cache.end()) {
            cache_miss = true;
            answer += 5;
        }
        else answer++;
        
        if (cacheSize > 0) {
            // 캐시값 age 증가
            for (iter = cache.begin(); iter != cache.end(); iter++) {
                iter->second++;
            }

            // 캐시가 다 찼을 때, cache miss인 경우에는 age가 가장 큰 도시를 캐시에서 제거
            if (cache_miss == true and cacheSize <= cache.size()) {
                vector<pair<string, int>> sorting_vect(cache.begin(), cache.end());
                sort(sorting_vect.begin(), sorting_vect.end(), byValue);

                cache.erase(sorting_vect.back().first);
            }
            cache[upper_city] = 0;
        }
    }
    
    return answer;
}