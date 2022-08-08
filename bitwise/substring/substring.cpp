#include "substring.h"

std::vector<string> generate_substring(string word){
    std::vector<string> result;
    int iterations = (1<<word.size());
    std::stringstream output;
    for (int i = 0; i < iterations; i++) {
        int j   = i;
        int pos = 0;
        while(j != 0){
            if(j&1) output << word[pos];
            j >>= 1;
            pos++;
        }
        result.push_back(output.str());
        output.str("");
    }
    return result;
}

namespace sub {
    void teste(){
        auto result = generate_substring("abcd");
        for(auto &item : result) std::cout << item << std::endl;
    }
};
