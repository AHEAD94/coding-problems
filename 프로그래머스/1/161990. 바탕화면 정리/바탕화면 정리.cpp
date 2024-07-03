#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_x = wallpaper.front().size();
    int min_y = wallpaper.size();
    int max_x = 0;
    int max_y = 0;
    
    for (auto iter_y = wallpaper.begin(); iter_y != wallpaper.end(); iter_y++) {
        int idx_y = iter_y - wallpaper.begin();
        string str = *iter_y;
        int str_len = str.size();

        for (auto idx_x = 0; idx_x < str_len; idx_x++) {
            if (str[idx_x] == '#') {
                min_x = min(min_x, idx_x);
                min_y = min(min_y, idx_y);
                max_x = max(max_x, idx_x);
                max_y = max(max_y, idx_y);
            }
        }
    }
    
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y + 1);
    answer.push_back(max_x + 1);
    
    return answer;
}