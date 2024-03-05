#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> people_sorted(people.size());
    
    copy(people.begin(), people.end(), people_sorted.begin());
    sort(people_sorted.begin(), people_sorted.end());
        
    while (!people_sorted.empty()) {
        answer++;
        
        // 가장 무거운 사람 탑승
        int weight_sum = people_sorted.back();
        people_sorted.pop_back();

        // 가장 가벼운 사람 탑승
        if (weight_sum + people_sorted.front() <= limit) {
            if (people_sorted.size() > 0) people_sorted.pop_front();
        }
    }

    return answer;
}