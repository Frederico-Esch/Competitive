#include "linked-list.h"

class Objeto {
    std::array<long long,(int)10e5> valores;
public:
    Objeto(){
        long long count = 0;
        for(auto& x : valores){
            x = count++;
        }
    }
};

int main() {
#ifdef RAW
    std::vector<Objeto*> vetor;
    freopen("raw.txt", "w", stderr);
#else
    std::vector<std::shared_ptr<Objeto>> vetor;
    freopen("shared.txt", "w", stderr);
#endif
#ifndef LINKED_LIST
    for(int i = 0; i < 9; i ++){
#ifdef RAW
        vetor.push_back(new Objeto);
#else
        vetor.push_back(std::make_shared<Objeto>());
#endif

        malloc_stats();
    }

    auto size = vetor.size();
    for(; size > 0; size--){
        vetor.erase(vetor.begin());
        malloc_stats();
    }

    for(int i = 0; i < 9; i++){
#ifdef RAW
        vetor.push_back(new Objeto);
#else
        vetor.push_back(std::make_shared<Objeto>());
#endif
        malloc_stats();
    }
#else
    teste_lista();
#endif
    return 0;
}
