#include <iostream>
#include <vector>
#include <queue>

constexpr int DIR_SIZE = 4;

using namespace std;

template<class T>
void PrintContainer(const T& container_begin, const T& container_end) {
    for (auto iter1 = container_begin; iter1 != container_end; iter1++) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(const vector<vector<int>>& paper, const vector<vector<int>>& directions, const pair<int, int>& pos, vector<vector<bool>>& visited, int& drawing_num, int& max_size) {
    int drawing_size = 0;
    queue<pair<int, int>> pos_queue;
    
    visited[pos.first][pos.second] = true;
    pos_queue.push(make_pair(pos.first, pos.second));
    
    while (!pos_queue.empty()) {
        int cur_row = pos_queue.front().first;
        int cur_col = pos_queue.front().second;
        pos_queue.pop();

        drawing_size++;
        
        for (int dir = 0; dir < DIR_SIZE; dir++) {
            int next_row = cur_row + directions[dir][0];
            int next_col = cur_col + directions[dir][1];
            
            if (0 <= next_row and next_row < paper.size() and 0 <= next_col and next_col < paper.front().size()) {
                if (visited[next_row][next_col] == false and paper[next_row][next_col] == 1) {
                    visited[next_row][next_col] = true;
                    pos_queue.push(make_pair(next_row, next_col));
                }
            }
        }
    }
    
    drawing_num++;
    max_size = max(max_size, drawing_size);
}

int main() {
    int max_row;
    int max_col;
    cin >> max_row;
    cin >> max_col;
    
    vector<vector<int>> paper(max_row, vector<int>(max_col, 0));
    vector<vector<bool>> visited(max_row, vector<bool>(max_col, false));
    
    for (auto iter1 = paper.begin(); iter1 != paper.end(); iter1++) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            int elem;
            cin >> elem;
            
            if (elem == 1) *iter2 = elem;
        }
    }
    
    //PrintContainer(painting.begin(), painting.end());
    
    vector<vector<int>> directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    int drawing_num = 0;
    int max_size = 0;
    
    for (auto iter1 = paper.begin(); iter1 != paper.end(); iter1++) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            size_t pos_row = iter1 - paper.begin();
            size_t pos_col = iter2 - (*iter1).begin();
            
            if (visited[pos_row][pos_col] == false and paper[pos_row][pos_col] == 1) {
                pair<int, int> pos{pos_row, pos_col};
                BFS(paper, directions, pos, visited, drawing_num, max_size);
            }
        }
    }
    
    cout << drawing_num << " " << max_size << endl;
    
    return 0;
}