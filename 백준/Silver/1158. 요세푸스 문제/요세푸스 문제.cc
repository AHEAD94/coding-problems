#include <iostream>
#include <vector>

int main () {
    uint16_t N = 0;
    uint16_t K = 0;
    std::cin >> N >> K;
    
    std::vector<uint16_t> nums;
    for (uint16_t i = 1; i <= N; ++i) {
        nums.emplace_back(i);
    }
    
    uint16_t idx = 0;
    
    std::cout << "<";
    while (!nums.empty()) {
        idx = (idx + K - 1) % nums.size();
        std::cout << nums[idx];
        if (nums.size() > 1) {
            std::cout << ", ";
        }
        nums.erase(nums.begin() + idx);
    }
    std::cout << ">" << std::endl;
    
    return 0;
}