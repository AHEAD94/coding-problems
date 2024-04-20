#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int name_len = name.length();
    
    int change_count = 0;
    
    for (int i = 0; i < name_len; i++) {
        if (name[i] < 'N')
            change_count += name[i] - 'A';
        else change_count += 1 + 'Z' - name[i];
    }
    
    int switch_count = name_len - 1;
    
    int name_idx = 1;
    while (name_idx < name_len) {
        if (name[name_idx] == 'A') {
            int left_len = name_idx - 1;
            
            while (name[name_idx] == 'A' and name_idx < name_len) {
                name_idx++;
            }
            int right_len = name_len - name_idx;
            
            switch_count = min(switch_count, left_len * 2 + right_len);
            switch_count = min(switch_count, right_len * 2 + left_len);
        }
        
        name_idx++;
    }
    
    answer = change_count + switch_count;
    
    return answer;
}