#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    vector<int> tempA = A;
    vector<int> tempB = B;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;

    sort(tempA.begin(), tempA.end());
    sort(tempB.begin(), tempB.end(), greater());
    
    for (int i = 0; i < tempA.size(); i++) {
        answer += (tempA[i] * tempB[i]); 
    }
    
    return answer;
}