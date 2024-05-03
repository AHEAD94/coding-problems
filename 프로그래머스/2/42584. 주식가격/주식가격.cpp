#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int prices_size = prices.size();
    vector<int> answer(prices_size, 0);
    stack<vector<int>> price_stack;

    for (int i = 0; i < prices_size; i++) {
        if (!price_stack.empty()) {
            while (price_stack.top()[1] > prices[i]) {
                int top_idx = price_stack.top()[0];
                answer[top_idx] = i - top_idx;
                price_stack.pop();
                if (price_stack.empty()) break;
            }
        }
        price_stack.push({i, prices[i]});
    }
    
    while (!price_stack.empty()) {
        int top_idx = price_stack.top()[0];
        answer[top_idx] = prices_size - 1 - top_idx;
        price_stack.pop();
    }

    return answer;
}