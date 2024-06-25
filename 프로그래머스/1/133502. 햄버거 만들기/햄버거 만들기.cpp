#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> ingre_vect{0};
    
    for (int ingre : ingredient) {
        if (ingre == 2 and ingre_vect.back() == 1) ingre_vect.back() = 12;
        else if (ingre == 3 and ingre_vect.back() == 12) ingre_vect.back() = 123;
        else if (ingre == 1 and ingre_vect.back() == 123) {
            ingre_vect.pop_back();
            answer++;
        }
        else ingre_vect.push_back(ingre);
    }    

    return answer;
}