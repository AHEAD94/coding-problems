using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long target_amount = 0;
    int increased_price = price;
    
    for (int i = 1; i <= count; i++) {
        target_amount += increased_price * i;
    }
    
    if (target_amount <= money) answer = 0;
    else answer = target_amount - money;

    return answer;
}