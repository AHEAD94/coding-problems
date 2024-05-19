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

void UpdateUser(unordered_map<string, User> &_user_info, string _uid, string _nick_name) {
    unordered_map<string, User>::iterator iter;
    
    iter = _user_info.find(_uid);
    if (iter == _user_info.end()) {
        User user(_uid, _nick_name);
        _user_info.insert(make_pair(_uid, user));
    }
    else iter->second.ChangeNickName(_nick_name);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, User> user_info;
    vector<pair<string, bool>> user_io_log;
    
    for (string text : record) {
        string command, uid, nick_name;
        stringstream ss(text);
        ss >> command;
        ss >> uid;
        ss >> nick_name;
        
        if (command == "Leave") 
            user_io_log.push_back(make_pair(uid, false));
        else {
            if (command == "Enter") 
                user_io_log.push_back(make_pair(uid, true));
            UpdateUser(user_info, uid, nick_name);
        }
    }
    
    unordered_map<string, User>::iterator iter;
    for (pair<string, bool> log : user_io_log) {
        string uid = log.first;
        bool io_info = log.second;
        
        iter = user_info.find(uid);
        if (iter != user_info.end()) {
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