#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int avail_chicken = chicken;
    
    while (avail_chicken >= 10) {
        answer += (avail_chicken / 10);
        avail_chicken = (avail_chicken / 10) + (avail_chicken % 10);
    }
    
    return answer;
}