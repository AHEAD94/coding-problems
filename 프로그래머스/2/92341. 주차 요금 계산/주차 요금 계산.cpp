#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

struct carInfo {
    int hour;
    int minute;
    int number;
    string in_out;
};

int getDiffMinutes(int h1, int m1, int h2, int m2) {
    int diff_hour = h2 - h1;
    int diff_min = m2 - m1;
    
    if (m1 > m2) {
        diff_hour--;
        diff_min += 60;
    }
    diff_min += diff_hour * 60;
    
    return diff_min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<carInfo> car_infos;
    vector<carInfo> in_infos;
    map<int, int> car_times;
    
    // 입출 정보 파싱
    for (string record : records) {
        string time, car_num, in_out;
        stringstream ss(record);
        ss >> time;
        ss >> car_num;
        ss >> in_out;
        
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 4));
        int number = stoi(car_num);
        
        carInfo car_info = {hour, minute, number, in_out};
        car_infos.push_back(car_info);
    }
    
    // 출차한 차량 주차시간 계산
    int infos_size = car_infos.size();
    for (int i = 0; i < infos_size; i++) {
        if (car_infos[i].in_out == "IN") in_infos.push_back(car_infos[i]);
        if (car_infos[i].in_out == "OUT") {
            int idx = -1;
            int in_size = in_infos.size();
            for (int j = 0; j < in_size; j++) {
                if (car_infos[i].number == in_infos[j].number) {
                    idx = j;
                    carInfo in = in_infos[j];
                    carInfo out = car_infos[i];
                    int t_diff = getDiffMinutes(in.hour, in.minute, out.hour, out.minute);
                    car_times[car_infos[i].number] += t_diff;
                    break;
                }
            }
            if (idx != -1) in_infos.erase(in_infos.begin() + idx);
        }
    }
    
    // 출차하지 않은 차량 주차시간 계산
    int in_size = in_infos.size();
    for (int i = 0; i < in_size; i++) {
        carInfo info = in_infos[i];
        int t_diff = getDiffMinutes(info.hour, info.minute, 23, 59);
        car_times[info.number] += t_diff;
    }
    
    // 요금 계산
    map<int, int>::iterator iter;
    for (iter = car_times.begin(); iter != car_times.end(); iter++) {
        int time = iter->second;
        int time_slice;
        
        if (time <= fees[0]) time_slice = 0;
        else time_slice = ceil((double)(time - fees[0]) / (double)fees[2]);
        
        int tot_fee = fees[1] + time_slice * fees[3];
        answer.push_back(tot_fee);
    }
    
    return answer;
}