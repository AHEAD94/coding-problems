#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

class MusicInfo {
private:
    int time_;
    string name_;
    string notes_;
    
public:
    MusicInfo(int time, string name, string notes) {
        this->time_ = time;
        this->name_ = name;
        this->notes_ = notes;
    }
    
    int getTime() { return this->time_; }
    string getName() { return this->name_; }
    string getNotes() { return this->notes_; }
    
    void printInfo() {
        cout << "play time : " << this->time_
             << ", name : " << this->name_
             << ", notes : " << this->notes_ << endl;
    }
};

void ParseData(string data, vector<string>& music_data) {
    stringstream ss(data);
    string token;

    while (getline(ss, token, ',')) {
        music_data.push_back(token);
    }
    
    return;
}

int GetPlayTime(string s, string e) {
    vector<string> str_times{s, e};
    vector<int> times;

    for (int i = 0; i < 2; i++) {
        stringstream ss(str_times[i]);
        string token;
        
        while (getline(ss, token, ':')) {
            if (token.empty()) 
                return 0;
            times.push_back(stoi(token));
        }
    }
    int s_min = times[0] * 60 + times[1];
    int e_min = times[2] * 60 + times[3];
    
    return e_min - s_min;
}

bool ByTime(MusicInfo m1, MusicInfo m2) {
    return m1.getTime() > m2.getTime();
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<MusicInfo> obj_music;
    vector<MusicInfo> candidates;

    // 입력을 파싱하여 객체에 담아 저장
    for (auto data : musicinfos) {
        vector<string> music_data;
        
        ParseData(data, music_data);
        int p_time = GetPlayTime(music_data[0], music_data[1]);
        MusicInfo info = MusicInfo(p_time, music_data[2], music_data[3]);
        obj_music.push_back(info);
    }
    
    // for (auto music : obj_music) {
    //     music.printInfo();
    // }
    
    // 음악 객체마다 음계 일치 확인
    for (auto music : obj_music) {
        string full_notes = "";
        string notes = music.getNotes();
        int note_size = notes.size();
        int note_idx = 0;
        int p_time = music.getTime();
        int t = 0;
        
        // 재생 시간만큼 음계를 반복하여 full_notes에 저장
        while (t < p_time) {
            full_notes += notes[note_idx];
            note_idx = (note_idx + 1) % note_size;
            t++;

            // 한 음계는 1분동안 재생되므로 #은 1분을 세지 않음
            if (notes[note_idx] == '#') {
                full_notes += notes[note_idx];
                note_idx = (note_idx + 1) % note_size;
            }
        }

        // 마지막에 #이 붙는다면 해당 음계까지 삭제 후 #이 붙지 않을 때까지 반복탐색
        int pos = full_notes.find(m);
        while (pos != string::npos) {
            if (full_notes[pos + m.size()] != '#') {
                candidates.push_back(music);
                break;
            }
            else full_notes.erase(0, pos + m.size() + 1);
            
            pos = full_notes.find(m);
        }
    }
    
    sort(candidates.begin(), candidates.end(), ByTime);
    
    if (!candidates.empty())
        answer = candidates.front().getName();

    return answer;
}