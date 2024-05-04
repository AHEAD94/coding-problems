#include <string>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<tuple<int, int, char>> memo;
    set<tuple<int, int, char>>::iterator iter;
    
    int curr_row = 5;
    int curr_col = 5;
    
    int dirs_len = dirs.length();
    for (int i = 0; i < dirs_len; i++) {
        int next_row = curr_row;
        int next_col = curr_col;
        
        if (dirs[i] == 'U')       next_row -= 1;
        else if (dirs[i] == 'D')  next_row += 1;
        else if (dirs[i] == 'L')  next_col -= 1;
        else                      next_col += 1;
        
        if (0 <= next_row and next_row < 11 and 
            0 <= next_col and next_col < 11) {
            iter = memo.find(make_tuple(curr_row, curr_col, dirs[i]));
            if (iter == memo.end()) {
                answer++;

                // 이동 전 좌표와 방향 기록
                memo.insert(make_tuple(curr_row, curr_col, dirs[i]));
                
                // 이동 후 좌표와 반대방향 기록
                char reverse_dir;
                if (dirs[i] == 'U')       reverse_dir = 'D';
                else if (dirs[i] == 'D')  reverse_dir = 'U';
                else if (dirs[i] == 'L')  reverse_dir = 'R';
                else                      reverse_dir = 'L';
                memo.insert(make_tuple(next_row, next_col, reverse_dir));
            }
            curr_row = next_row;
            curr_col = next_col;
        }
    }
    
    return answer;
}