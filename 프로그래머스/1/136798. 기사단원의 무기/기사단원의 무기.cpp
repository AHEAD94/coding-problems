#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getNumOfDivisors(int number) {
    int num_of_divisors = 0;
    
    for (int i = 1; i <= (int)sqrt(number); i++) {
        if (number % i == 0) {
            num_of_divisors++;
            
            if (number / i != i) num_of_divisors++;
        }
    }
    
    return num_of_divisors;
}

int solution(int number, int limit, int power) {
    int answer = 0;
        
    for (int knight = 1; knight <= number; knight++) {
        int weapon_power = getNumOfDivisors(knight);
        
        if (weapon_power > limit) 
            answer += power;
        else answer += weapon_power;
    }
    
    return answer;
}