#include <string>
#include <vector>

using namespace std;

int solution(int age) {
    int answer = 0;
    
    int year_now = 2022;
    answer = year_now - age + 1;
    
    return answer;
}