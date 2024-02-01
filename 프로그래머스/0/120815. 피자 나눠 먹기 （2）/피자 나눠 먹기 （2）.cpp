#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int pizza = 1;
    while ((pizza * 6) % n != 0) {
        pizza++;
    }
    
    answer = pizza;

    return answer;
}