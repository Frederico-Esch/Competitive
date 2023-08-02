#include <iostream>
#include <unordered_map>
#include <vector>

int solve(int n, std::vector<int> nums)
{
    int result = 0;
    std::unordered_map<int, int> subsets;

    std::vector<int> cumulative(n);
    int sum = 0;
    for (int i =0; i < n; i++) {
        sum += nums[i];
        cumulative[i] = sum;
        cumulative[i] %= n;
    }

    for (auto val : cumulative) {
        if (subsets.find(val) != subsets.end()){
            subsets[val] += 1;
        } else {
            subsets[val] = 1;
        }
    }

    for (auto items : subsets) {
        if(items.first == 0) {
            result += items.second;
        } else if(items.second > 1) {
            result += items.second;
        }
        std::cout << items.first << " -> " << items.second << std::endl;
    }

    return result;
}

int main()
{

    std::cout << solve(5, {4, 5, 0, 4, 2}) << std::endl;
}
