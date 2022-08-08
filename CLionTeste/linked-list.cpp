#include "linked-list.h"

inline auto _generate = [](){
    std::stringstream val("");
    for(int i = 0; i < 10e5; i++){
        val << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    }
    return val.str();
};
const string giga_string = _generate();

template<typename T>
class Node {
    T val;
#ifdef RAW
    typedef Node<T>* Next_type;
#else
    typedef std::shared_ptr<Node<T>> Next_type;
#endif
    Next_type Next;

public:
    Node(T val, Next_type next = nullptr): val(val), Next(next){}
    T getVal(){
        return val;
    }
    Next_type next(){
        return Next;
    }

    void insert(Next_type next){
        if(this->Next == nullptr)
            this->Next = std::move(next);
        else
            this->Next->insert(std::move(next));
    }
};

#ifdef RAW
    template <typename T>
    using ptr = Node<T>*;

    template<typename T>
    auto make_new = [](T val, ptr<T> next){
        return new Node(val, next);
    };
#else
    template <typename T>
    using ptr = std::shared_ptr<Node<T>>;
    template<typename T>
    inline auto make_new = [](T val, std::shared_ptr<Node<T>> next) {
        return std::make_shared<Node<T>>(val, next);
    };
#endif
void teste_lista(){

    malloc_stats();
    ptr<string> lista = make_new<string>("A" + giga_string, nullptr);
    lista->insert(make_new<string>("B" + giga_string, nullptr));
    lista->insert(make_new<string>("C" + giga_string, nullptr));
    malloc_stats();

    while(lista != nullptr){
        std::cout << lista->getVal()[0] << std::endl;
        lista = lista->next();
    }
    malloc_stats();
    //std::cout << std::endl << std::endl << lista->getVal() << std::endl;
}