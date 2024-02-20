#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max_comm_div = 0;
    int min_comm_multi = 0;
    int multiple = 0;
    
    for (int i = 1; i <= min(n, m); i++) {
        if (n % i == 0 and m % i == 0) {
            max_comm_div = i;
        }
    }
    answer.insert(answer.begin(), max_comm_div);
    
    multiple = n * m;
    for (int i = 1; i <= multiple; i++) {
        if (multiple % i == 0) {
            if ((multiple / i) % n == 0 and (multiple / i) % m == 0) {
                min_comm_multi = multiple / i;
            }
        }
    }
    answer.push_back(min_comm_multi);
        
    return answer;
}