#include "sort.h"
int count_bits(int num){
    int result = 0;
    while(num != 0) {
        num &= num-1;
        result++;
    }
    return result;
}

std::vector<int> sortByBits(std::vector<int> arr){
    std::vector<int> vetor(arr);

    auto sorter = [](int a, int b) {
        auto ba = count_bits(a);
        auto bb = count_bits(b);
        if( ba == bb ){
            return a < b;
        }
        return ba < bb;
    };
    std::sort(vetor.begin(), vetor.end(), sorter);
    return vetor;
}

namespace sorting {
    void teste(){
        std::vector<int> arr = {0,1,2,3,4,5,6,7,8};
        for (const auto &item: sortByBits(arr)) {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
    }
}
