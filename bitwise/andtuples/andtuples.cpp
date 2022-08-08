#include "andtuples.h"

int calculate(std::vector<int> valores){
    std::unordered_map<int, int> mapa;
    for (int i = 0; i < valores.size(); i++) {
        for (int j = 0; j < valores.size(); j++) {
            auto val = (valores[i] & valores[j]);
            if (mapa.find(val) == mapa.end()) {
                mapa[val] = 0;
            }
            mapa[val]++;
        }
    }

    int result = 0;
    for(auto &i: valores){
        for(auto &item : mapa){
            if ((item.first&i) == 0) {
                result += item.second;
            }
        }
    }
    return result;
}

namespace andtuples {
    void teste(){
        std::vector<int> valores = {2,1,3};
        std::cout << calculate(valores) << std::endl;
    }
};
