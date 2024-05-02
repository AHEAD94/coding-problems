#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int prices_size = prices.size();
    
    for (int i = 0; i < prices_size; i++) {
        int count = 0;
        for (int j = i + 1; j < prices_size; j++) {
            count++;
            if (prices[i] > prices[j]) break;
        }
        answer.push_back(count);
    }
    
    return answer;
}