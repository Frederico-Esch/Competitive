#include "fifth.h"

std::vector<int> findClosestElements(std::vector<int> arr, int k, int x) {

    auto cmp = [x](int a, int b){
        int abs_A = std::abs(a - x);
        int abs_B = std::abs(b - x);

        if(abs_A < abs_B || (abs_A == abs_B && a < b)){
            return false;
        }else{
            return true;
        }
    };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
    std::priority_queue<int, std::vector<int>, std::greater<int>> result;
    std::vector<int> sol;

    for (auto &num: arr) {
        pq.push(num);
    }
    for (int i = 0; i < k; ++i) {
        result.push(pq.top());
        pq.pop();
    }
    while (!result.empty()) {
        sol.push_back(result.top());
        result.pop();
    }
    return sol;
}

void fifth_work(){
    int k, x, n;
    std::vector<int> nums;
    std::cin >> k >> x;
    while(std::cin >> n) nums.push_back(n);

    auto r = findClosestElements(nums, k, x);
    for (const auto &item: r) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}
