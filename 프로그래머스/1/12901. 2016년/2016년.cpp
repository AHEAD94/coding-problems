#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    set<int> bigMonth = {1, 3, 5, 7, 8, 10, 12};
    set<int> smallMonth = {4, 6, 9, 11};
    vector<string> week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"}; 
    int totalDays = b - 1; // 시작일 제외
    
    /* 해당 월일까지 총 며칠이 있는지 계산 후 요일을 7로 나눈 나머지로 계산 */
    
    for (int i = 1; i < a; i++) { // 마지막 달의 날들은 포함하지 않음
        if (bigMonth.find(i) != bigMonth.end())             totalDays += 31;
        else if (smallMonth.find(i) != smallMonth.end())    totalDays += 30;
        else                                                totalDays += 29;
    }
    
    int dayOfWeek = totalDays % 7;
    answer = week[dayOfWeek];
    
    return answer;
}