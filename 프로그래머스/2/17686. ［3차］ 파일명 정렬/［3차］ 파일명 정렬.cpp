#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileName {
    int index;
    string head;
    int number;
};

bool byName(fileName f1, fileName f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        return f1.number < f2.number;
    }
    return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> sorting_vect;
    int files_size = files.size();
    
    for (int i = 0; i < files_size; i++) {
        bool is_num = false;
        string token = "";
        fileName splited = {i, "", 0};
        
        string file = files[i];
        int file_len = file.length();
        for (char file_char : file) {
            if (is_num == false and '0' <= file_char and file_char <= '9') {
                splited.head = token;
                token = "";
                is_num = true;
            }
            if (is_num == true and !('0' <= file_char and file_char <= '9')) {
                if (token != "") splited.number = stoi(token);
                token = "";
                break;
            }
            token += file_char;
        }
        if (token != "") splited.number = stoi(token);
        
        int head_len = splited.head.length();
        for (int j = 0; j < head_len; j++) {
            splited.head[j] = tolower(splited.head[j]);
        }
        sorting_vect.push_back(splited);
    }
    
    sort(sorting_vect.begin(), sorting_vect.end(), byName);
    
    for (fileName sorted : sorting_vect) {
        answer.push_back(files[sorted.index]);
    }
    
    return answer;
}