#include "hamming.h"

std::unordered_map<int, int> values;

int count_ones(int value){
    if(values.find(value) != values.end()) return values[value];
    int count = 0;
    while(value != 0){
        count ++;
        value &= value-1;
    }

    values[value] = count;
    return count;
}

int hamming_dist(int a, int b){
    int dif = a^b;
    auto val = count_ones(dif);
    return val;
}

int sum_hamming(std::vector<int> nums){
    int result = 0;
    for (int i = 0; i < 30; i++) {
        int zeros = 0, ones = 0, val = 1<<i;
        for(auto &num : nums){
            if(num&val) ones++;
            else       zeros++;
        }
        result += zeros*ones;
    }
    return result;
}

namespace hamming {
    void teste(){
        std::cout << hamming_dist(1, 4) << std::endl;
    }

    void teste_2(){
        std::cout << sum_hamming({4, 14, 2}) << std::endl;
    }
}
