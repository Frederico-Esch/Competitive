#include <algorithm>
#include<bits/stdc++.h>
#include <cstdio>
typedef std::string string;


auto main() -> int {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int k, x;
    std::unordered_map<int, int> valores;
    std::vector<std::pair<int, int>> results;
    std::cin >> k;

    while(std::cin >> x) {
        auto valor = valores.find(x);
        if(valor != valores.end())
            results.push_back(std::make_pair(x, valor->second));
        valores[k-x] = x;
    }

    for(auto& i : results){
        std::cout << i.first << ", " << i.second << std::endl;
    }

    return 0;
}

