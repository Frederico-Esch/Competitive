#include "3NP1.h"

int find_odd_one_out(std::vector<int> arr){
    std::vector<int> vetor(32, 0);
    int i = 0;
    int result = 0;
    auto f = [&](int val){
        int pos = 0;
        while(val != 0){
            if(val&1) vetor[pos] = (vetor[pos] + 1)%3;
            pos++;
            val >>= 1;
        }
    };

    auto translate = [&](int a){
        result += a*(1<<i);
        i++;
    };
    std::for_each(arr.begin(), arr.end(), f);
    std::for_each(vetor.begin(), vetor.end(), translate);
    return result;
}

namespace TNPO {
    void teste(){
        std::cout << find_odd_one_out({1, 2, 3, 6, 5, 5, 3, 2, 1, 1, 2, 5, 3}) << std::endl;
    }
};
