#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> l_pos = {3, 0};
    pair<int, int> r_pos = {3, 2};
    
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        // cout << "- " << *iter << " -" << endl;
        
        if (*iter == 1 or *iter == 4 or *iter == 7 or *iter == '*') {
            if (*iter == '*') l_pos = {3, 0};
            else l_pos = {(*iter - 1) / 3, (*iter - 1) % 3};
            answer += 'L';
        }   
        if (*iter == 3 or *iter == 6 or *iter == 9 or *iter == '#') {
            if (*iter == '#') r_pos = {3, 2};
            else r_pos = {(*iter - 1) / 3, (*iter - 1) % 3};
            answer += 'R';
        }
        if (*iter == 2 or *iter == 5 or *iter == 8 or *iter == 0) {
            pair<int, int> num_pos;
            if (*iter == 0) num_pos = {3, 1};
            else num_pos = {(*iter - 1) / 3, (*iter - 1) % 3};
            
            // cout << "MIDDLE COLUNM" << endl;
            // cout << "Dist L : " << GetDist(l_pos, num_pos) << endl;
            // cout << "Dist R : " << GetDist(r_pos, num_pos) << endl;
            
            if (GetDist(l_pos, num_pos) < GetDist(r_pos, num_pos)) {
                l_pos = num_pos;
                answer += 'L';
            }
            if (GetDist(l_pos, num_pos) > GetDist(r_pos, num_pos)) {
                r_pos = num_pos;
                answer += 'R';
            }
            if (GetDist(l_pos, num_pos) == GetDist(r_pos, num_pos)) {
                if (hand.front() == 'l') l_pos = num_pos;
                if (hand.front() == 'r') r_pos = num_pos;
                answer += toupper(hand.front());
            }
        }
        
        // cout << "L (" << l_pos.first << ", " << l_pos.second << ")" << endl;
        // cout << "R (" << r_pos.first << ", " << r_pos.second << ")" << endl;
    }
    
    return answer;
}