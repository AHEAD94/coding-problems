#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    
    int num1 = box[0] / n;
    int num2 = box[1] / n;
    int num3 = box[2] / n;
    
    answer = num1 * num2 * num3;
    
    return answer;
}