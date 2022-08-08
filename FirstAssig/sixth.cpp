#include "sixth.h"

int distributeCandies(std::vector<int> candies){
    std::unordered_set<int> c;
    auto n = candies.size()/2;

    for (const auto &candy: candies) {
        c.insert(candy);
    }
    return std::min(n, c.size());
}

void sixth_work(){
    int a;
    std::vector<int> valores;
    while(std::cin >> a) valores.push_back(a);
    std::cout << std::endl << distributeCandies(valores) << std::endl;
}