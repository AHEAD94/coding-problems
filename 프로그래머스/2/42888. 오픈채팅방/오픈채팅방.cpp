#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class User {
private:
    string uid;
    string nick_name;
public:
    User(string _uid, string _nick_name) {
        this->uid = _uid;
        this->nick_name = _nick_name;
    }
    string GetUID();
    string GetNickName();
    void ChangeNickName(string _nick_name);
};

string User::GetUID() {
    return this->uid;
}

string User::GetNickName() {
    return this->nick_name;
}

void User::ChangeNickName(string _nick_name) {
    this->nick_name = _nick_name;
}

void PushUser(unordered_map<string, User> &_chat_room, User _user) {
    unordered_map<string, User>::iterator iter;
    
    iter = _chat_room.find(_user.GetUID());
    if (iter == _chat_room.end())
        _chat_room.insert(make_pair(_user.GetUID(), _user));
    else iter->second.ChangeNickName(_user.GetNickName());
}

void ChangeUserNickName(unordered_map<string, User> &_chat_room, string _uid, string _nick_name) {
    unordered_map<string, User>::iterator iter;
    
    iter = _chat_room.find(_uid);
    if (iter != _chat_room.end()) iter->second.ChangeNickName(_nick_name);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, User> chat_room;
    vector<pair<string, bool>> user_io_log;
    
    for (string text : record) {
        string command = "";
        string uid = "";
        string nick_name = "";
        
        stringstream ss(text);
        ss >> command;
        ss >> uid;
        if (command != "Leave") ss >> nick_name;
        
        if (command == "Enter") {
            User user(uid, nick_name);
            PushUser(chat_room, user);
            user_io_log.push_back(make_pair(uid, true));
        }
        else if (command == "Leave") {
            user_io_log.push_back(make_pair(uid, false));
        }
        else if (command == "Change") 
            ChangeUserNickName(chat_room, uid, nick_name);
        else;
    }
    
    unordered_map<string, User>::iterator iter;
    for (pair<string, bool> log : user_io_log) {
        string uid = log.first;
        bool io_info = log.second;
        
        iter = chat_room.find(uid);
        if (iter != chat_room.end()) {
            User user = iter->second;
            
            string text_log = "";
            if (io_info == true)
                text_log = user.GetNickName() + "님이 들어왔습니다.";
            else text_log = user.GetNickName() + "님이 나갔습니다.";
            answer.push_back(text_log);
        }
    }
    
    return answer;
}