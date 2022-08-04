#include <array>
#include<bits/stdc++.h>
#include <cstdlib>
#include <iostream>
typedef std::string string;


auto main() -> int {
    std::array<int, 10> arr;
    for (auto& valor : arr) {
        valor = rand()%100;
    }
    std::sort(arr.begin(), arr.end()-5);
    std::sort(arr.begin()+5, arr.end());
    for (auto& valor : arr) {
        std::cout << valor << std::endl;
    }
    return 0;
}
