#include<bits/stdc++.h>
typedef std::string string;

#define AMOUNT_OF_NUMBERS 6
#define TREE_SIZE         15 //2*2^ceil(log2 6) - 1 = 2^4 - 1 = 15

struct Range {
    int begin;
    int end;

    bool leaf(){
        return begin == end;
    }

    std::pair<Range, Range> mid(){
        int _mid = (begin+end)/2;

        Range lower_mid(begin, _mid);
        Range upper_mid(_mid+1, end);
        return {lower_mid, upper_mid,};
    }

    size_t range_size(){
        return end - begin +1;
    }

    Range(int begin = 0, int end = 0):begin(begin), end(end){}
};

void build_tree(size_t node, Range node_range /*what range this node covers */,
        std::array<int, AMOUNT_OF_NUMBERS>& initial, std::array<int, TREE_SIZE>& tree){

    if (node_range.leaf())
        tree[node] = initial[node_range.begin];
    else{

        auto [lower_mid, upper_mid] = node_range.mid();
        int left_child = node*2 + 1;
        int right_child = node*2 + 2;

        build_tree(left_child, lower_mid, initial, tree);
        build_tree(right_child, upper_mid, initial, tree);

        tree[node] = tree[left_child] + tree[right_child]; //I'm doing a sum query problem, so here I set the logic for building it
    }
}

void spread_lazy(size_t node, Range node_range, std::array<int, TREE_SIZE>& tree, std::array<int, TREE_SIZE>& lazy){
    if (lazy[node] == 0) return;
    tree[node] += lazy[node]*node_range.range_size();

    int left_child  = node*2 +1;
    int right_child = node*2 +2;

    if (left_child < TREE_SIZE) lazy[left_child]  = lazy[node];
    if(right_child < TREE_SIZE) lazy[right_child] = lazy[node];

    lazy[node] = 0;
}

int update_query(size_t node, int query_val, Range node_range, Range query_range, std::array<int, TREE_SIZE>& tree, std::array<int, TREE_SIZE>& lazy){

    if (query_range.begin <= node_range.begin && query_range.end >= node_range.end){
        int to_sum = query_val*node_range.range_size();
        tree[node] += to_sum;

        int left_child  = node*2 +1;
        int right_child = node*2 +2;

        if (left_child < TREE_SIZE) lazy[left_child]  += query_val;
        if(right_child < TREE_SIZE) lazy[right_child] += query_val;

        return to_sum;
    }
    else if(query_range.begin > node_range.end || query_range.end < node_range.begin){
        return 0;
    }

    auto [lower, upper] = node_range.mid();

    int left_child  = node*2 +1;
    int right_child = node*2 +2;

    int to_sum = 0;
    to_sum += update_query(left_child,  query_val, lower, query_range, tree, lazy);
    to_sum += update_query(right_child, query_val, upper, query_range, tree, lazy);
    tree[node] += to_sum;
    return to_sum;
}

int query(size_t node, Range query_range, Range node_range, std::array<int, TREE_SIZE>& tree, std::array<int, TREE_SIZE>& lazy){
    //total   overlap
    if (query_range.begin <= node_range.begin && query_range.end >= node_range.end){
        spread_lazy(node, node_range, tree, lazy);
        return tree[node];
    }

    //no      overlap
    else if(query_range.begin > node_range.end || query_range.end < node_range.begin){
        return 0;
    }
    //partial overlap
    spread_lazy(node, node_range, tree, lazy);

    int left_child = node*2 + 1;
    int right_child = node*2 + 2;
    auto [lower_range, higher_range] = node_range.mid();

    int result = 0; //As I'm doing a sum the neutral value is 0
    result += query(left_child, query_range, lower_range, tree, lazy);
    result += query(right_child, query_range, higher_range, tree, lazy);

    return result;

}

auto main() -> int {
    std::array<int, 15> tree;
    std::array<int, 15> lazy; lazy.fill(0);
    std::array<int,  6> vals = {1,2,3,4,5,6};
    build_tree(0, Range(0, AMOUNT_OF_NUMBERS-1), vals, tree);

    std::cout << query(0, Range(0, 3), Range(0, 5), tree, lazy) << std::endl;
    std::cout << query(0, Range(2, 4), Range(0, 5), tree, lazy) << std::endl;
    std::cout << query(0, Range(2, 2), Range(0, 5), tree, lazy) << std::endl;

    update_query(0, 4, Range(0, 5), Range(1, 4), tree, lazy);

    std::cout << query(0, Range(0, 3), Range(0, 5), tree, lazy) << std::endl;
    std::cout << query(0, Range(2, 4), Range(0, 5), tree, lazy) << std::endl;
    std::cout << query(0, Range(2, 2), Range(0, 5), tree, lazy) << std::endl;

    return 0;
}
