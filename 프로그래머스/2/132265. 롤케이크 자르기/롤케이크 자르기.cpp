#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = -1;
    
    map<int, int> mapA;
    map<int, int> mapB;
    
    size_t size = topping.size();
    for (size_t i = 0; i < size; i++) {
        mapA[topping[i]]++;    
    }
    int countA = mapA.size();
    int countB = 0;
    
    int cases = 0;
    for (size_t i = 0; i < size; i++) {
        mapA[topping[i]]--;
        mapB[topping[i]]++;
        
        if (mapA[topping[i]] == 0) {
            mapA.erase(topping[i]);
        }
        
        if (mapA.size() == mapB.size()) cases++;
    }
    answer = cases;
    
    return answer;
}