#include "longest.h"

int count_consecutive_ones(int& n){
    int count = 0;
    while(n&1){
        n>>=1;
        count ++;
    }
    return count;
}

int max_longest(int n){
    int max = 0, val, num = n;
    while(num != 0){
        while(!(num & 1) && num != 0) num>>=1;

        val = count_consecutive_ones(num);
        if(val > max) max = val;
    }
    return max;
}

namespace longest {
    void teste(){
        std::cout << max_longest(156) << std::endl;
    }
}