#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool SortByValue1(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool SortByValue2(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first; // 재생 횟수가 같다면 고유번호가 낮은 노래 먼저 선택
    }
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_map;
    vector<pair<int, int>> idx_play_pairs;
    int genres_size = genres.size();
    
    // 장르별 재생 수
    for (int i = 0; i < genres_size; i++) {
        genre_map[genres[i]] += plays[i];
    }
    vector<pair<string, int>> sorted_genre(genre_map.begin(), genre_map.end());
    sort(sorted_genre.begin(), sorted_genre.end(), SortByValue1);
    
    // 재생 수 기준 정렬
    for (int i = 0; i < genres_size; i++) {
        idx_play_pairs.push_back(make_pair(i, plays[i]));
    }
    sort(idx_play_pairs.begin(), idx_play_pairs.end(), SortByValue2);
    
    // 베스트 앨범 반영
    int sorted_genre_size = sorted_genre.size();
    for (int i = 0; i < sorted_genre_size; i++) {
        int music_limits = 0;
        
        for (int j = 0; j < genres_size; j++) {
            if (genres[idx_play_pairs[j].first] == sorted_genre[i].first) {
                answer.push_back(idx_play_pairs[j].first);
                music_limits++;
                
                if (music_limits >= 2) break;
            }
        }
    }
    
    return answer;
}