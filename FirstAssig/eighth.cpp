#include "eighth.h"

std::vector<int> smallestRange(std::vector<std::vector<int>> nums){
    int k = nums.size();
    std::unordered_map<int, int> cnt;
    std::vector<int>  result;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> left;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> right;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            left.push({nums[i][j], i});
        }
    }
    //std::sort(vetor.begin(), vetor.end());
    //result = {vetor[0].first, vetor[vetor.size()-1].first};

    while (left.size() > 0){
        cnt[left.top().second] ++;
        while (cnt.size() == k){
            if((result.empty()) ||
               (right.top().first - left.top().first <  result[1] - result[0]) ||
               (right.top().first - left.top().first == result[1] - result[0] && left.top().first < result[0])){
                 result = {left.top().first, right.top().first};
            }

            auto rem = right.top().second; right.pop();
            cnt[rem]--;
            if(cnt[rem] == 0) cnt.erase(rem);
        }

        right.push(left.top());
        left.pop();
    }
    return result;
}

void eighth_work(){
    auto result = smallestRange({{4,10,15,24,26},{0,9,12,20},{5,18,22,30}});
    std::cout << result[0] << ", " << result[1] << std::endl;
}