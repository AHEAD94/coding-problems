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
        if (f1.number == f2.number) 
            return f1.index < f2.index;
        return f1.number < f2.number;
    }
    return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> sorting_vect;
    int files_size = files.size();
    
    for (int i = 0; i < files_size; i++) {
        string head = "";
        string number = "";
        
        int file_len = files[i].length();
        for (int j = 0; j < file_len; j++) {
            if ('0' <= files[i][j] and files[i][j] <= '9') {
                number += files[i][j];
                if (!('0' <= files[i][j + 1] and files[i][j + 1] <= '9')) break;
            }
            else head += files[i][j];
        }
         
        int head_len = head.length();
        for (int j = 0; j < head_len; j++) {
            head[j] = tolower(head[j]);
        }
        
        fileName file_name = {i, head, stoi(number)};
        sorting_vect.push_back(file_name);
    }
    sort(sorting_vect.begin(), sorting_vect.end(), byName);
    
    for (fileName sorted : sorting_vect) {
        answer.push_back(files[sorted.index]);
    }
    
    return answer;
}