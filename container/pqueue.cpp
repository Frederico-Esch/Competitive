#include<bits/stdc++.h>
#include <cstdio>
typedef std::string string;

class Produto {
    string nome;
    int quantity;
public:
    Produto(string nome, int quantity) : nome(nome), quantity(quantity){}
    int getQuantity() const { return quantity; };
    string getNome() const { return nome; };
};

template<typename comp>
class Produto_Comparator {
public:
    bool operator()(Produto a, Produto b){
        comp comparator;
        return comparator(a.getQuantity(), b.getQuantity());
    }
    bool operator()(std::shared_ptr<Produto> a, std::shared_ptr<Produto> b){
        comp comparator;
        return comparator(a->getQuantity(), b->getQuantity());
    }
};


auto main() -> int {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    std::priority_queue<int> queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> outro;
    std::priority_queue<std::shared_ptr<Produto>, std::vector<std::shared_ptr<Produto>>, Produto_Comparator<std::greater<int>>> produtos;

    int x;
    for (int i = 0; i < 10; i++) {
        std::cin >> x;
        queue.push(x);
        outro.push(x);
    }
    std::cout << std::endl << "SIZE: "  <<  queue.size() << std::endl << std::endl;
    for (; !queue.empty() ;) {
        std::cout << queue.top() << std::endl;
        queue.pop();
    }

    std::cout << std::endl << std::endl;
    for (; !outro.empty() ;) {
        std::cout << outro.top() << std::endl;
        outro.pop();
    }

    string nome;
    for (int i = 0; i < 5; i++) {
        std::cin >> nome >> x;
        produtos.push(std::make_shared<Produto>(nome, x));
    }

    std::shared_ptr<Produto> last;
    for (; !produtos.empty() ;) {
        std::cout << produtos.top()->getNome() << produtos.top()->getQuantity() << std::endl;
        last = produtos.top();
        produtos.pop();
    }
    std::cout << std::endl << last.use_count() << std::endl;
    return 0;
}
