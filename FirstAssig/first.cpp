#include "first.h"

int firstUniqChar(string s){
    std::unordered_map<char, int> visited;
    int pos = 0;
    for (const auto &item: s) {
        if(visited.find(s[pos]) != visited.end()){
            visited[item] += 1;
            if(visited.find(s[pos])->second > 1){
                while(pos < s.size() && visited.find(s[pos]) != visited.end() && visited.find(s[pos])->second > 1){
                    pos++;
                }
            }
        }else{
            visited[item] = 1;
        }
        if(pos >= s.size()){
            pos = -1;
            break;
        }
    }
    return pos;
}

void first_work(){
    string s;
    while(std::cin >> s){
        std::cout << firstUniqChar(s) << std::endl << std::endl;
    }
}