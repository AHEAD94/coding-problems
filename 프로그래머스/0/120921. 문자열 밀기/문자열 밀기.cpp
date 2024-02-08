#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    vector<char> vectA(A.begin(), A.end());
    vector<char> vectB(B.begin(), B.end());
    char alphabet = '\n';
    
    for (int i = 0; i < vectA.size(); i++) {
        if (vectA == vectB) {
            break;
        }
        else {
            alphabet = vectA[vectA.size() - 1];
            vectA.erase(vectA.end() - 1);
            vectA.insert(vectA.begin(), alphabet);
            answer++;
        }
    }
    
    if (answer == vectA.size()) {
        answer = -1;
    }
    
    return answer;
}