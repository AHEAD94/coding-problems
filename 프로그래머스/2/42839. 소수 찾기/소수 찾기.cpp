#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool IsPrimeNum(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

void DFS(string numbers, int num_len, vector<bool> &visited, int depth, string st_num, set<int> &permutations) {
    if (depth > num_len) return;
    
    if (st_num != "") permutations.insert(stoi(st_num));
    
    for (int i = 0; i < num_len; i++) {
        if (visited[i] == false) {            
            visited[i] = true;
            DFS(numbers, num_len, visited, depth + 1, st_num + numbers[i], permutations);
            visited[i] = false;
        }
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    int num_len = numbers.length();
    vector<bool> visited(num_len, false);
    set<int> permutations;
    
    DFS(numbers, num_len, visited, 0, "", permutations);
    
    set<int>::iterator iter;
    for (iter = permutations.begin(); iter != permutations.end(); iter++) {
        if (IsPrimeNum(*iter)) answer++;
    }
    
    return answer;
}