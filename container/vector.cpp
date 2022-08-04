#include <algorithm>
#include<bits/stdc++.h>
typedef std::string string;


auto main() -> int {
    std::vector<int> valores(10, 20);
    std::for_each(valores.begin(), valores.end(), [](auto i){std::cout << i << std::endl;});
    return 0;
}
