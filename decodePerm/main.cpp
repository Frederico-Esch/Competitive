#include "main.h"

std::vector<int> decode(std::vector<int> encoded){
    int n = encoded.size(), val1 = 0, val = 0;
    std::vector<int> decoded;
    for (int i = 1; i < n+2; i++) {
        val1 ^= i;
    }

    for (int i = 1; i < n; i++) {
        if (i%2 == 1) {
            val ^= encoded[i];
        }
    }
    decoded.push_back(val1^val);
    for(auto &num : encoded){
        decoded.push_back(num^decoded.back());
    }
    return decoded;
}

auto main() -> int {

    std::cout << []() -> string {std::stringstream ss; for(auto i : decode({2, 1})) ss << i << " "; return ss.str();}() << std::endl;

    return 0;
}
