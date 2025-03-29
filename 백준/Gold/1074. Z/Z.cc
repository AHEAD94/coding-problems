#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    
    int count = 0;
    
    int map_size = pow(2, N);
    while (map_size >= 2) {
        int z_point = 4; // Z를 그릴 때 지나는 점의 순서
        if (r < map_size / 2) z_point /= 2;
        if (c < map_size / 2) z_point -= 1;
        
        count += pow(map_size / 2, 2) * (z_point - 1);
        
        if (z_point > 2) r -= map_size / 2;
        if (z_point % 2 == 0) c -= map_size / 2;
        map_size /= 2;
    }
    
    cout << count << endl;
    
    return 0;
}