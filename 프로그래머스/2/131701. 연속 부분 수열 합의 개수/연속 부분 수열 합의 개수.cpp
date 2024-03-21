#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int tot_size = elements.size();
    set<int> num_set;
    
//     for (int sub_size = 1; sub_size <= tot_size; sub_size++) { // 부분문자열 길이 증가
//         for (int i = 0; i < tot_size; i++) { // 전체 문자열 순회
//             int sum = 0;
            
//             for (int j = i; j < i + sub_size; j++) { // 부분문자열 길이만큼 순회
//                 sum += elements[j % tot_size];
//             }
//             num_set.insert(sum);
//         }
//     }
//     answer = num_set.size();
    
    for (int i = 0; i < tot_size; i++) { // 전체 문자열 순회
        int sum = 0;

        // 시작 인덱스로부터 모든 부분문자열 길이만큼 합 계산
        for (int j = i; j < i + tot_size; j++) { 
            sum += elements[j % tot_size];
            num_set.insert(sum);
        }
    }
    answer = num_set.size();
    
    return answer;
}