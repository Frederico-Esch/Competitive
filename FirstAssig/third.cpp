#include "third.h"

int solve(std::vector<int> nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int result = 0;
    for (const auto &item: nums) pq.push(item);

    int lesser[2];
    while(pq.size() > 1){
        lesser[0] = pq.top();
        pq.pop();
        lesser[1] = pq.top();
        pq.pop();
        pq.push(lesser[0] + lesser[1]);
        result += lesser[0] + lesser[1];
    }
    return result;
}

void third_work(){
    std::vector<int> valores;
    int x;
    while(std::cin >> x) valores.push_back(x);
    std::cout << std::endl << solve(valores) << std::endl;
}