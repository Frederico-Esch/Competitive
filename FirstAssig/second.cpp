#include "second.h"

int findKthLargest(std::vector<int> nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (const auto &item: nums) {
        q.push(item);
        if(q.size() > k) q.pop();
    }
    return q.top();
}

void second_work() {
    int k, n, x;
    std::vector<int> vetor;
    std::cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        vetor.push_back(x);
    }
    std::cout << findKthLargest(vetor,k) << std::endl;
}