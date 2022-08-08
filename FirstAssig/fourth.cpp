#include "fourth.h"

int maximumScore(int a, int b, int c){
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    pq.push(a);
    pq.push(b);
    pq.push(c);

    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    c = pq.top();

    int result = 0;
    if(a <= c-b) {
        result = b+a;
    }
    else {
        int dist = c-b;
        a -= dist;
        c -= dist;
        result = dist + a;

        c -= a/2;
        b -= a - a/2;
        result += std::min(c,b);
    }
    return result;
}

void fourth_work(){
    int a, b, c;
    for (int i = 0; i < 2; ++i) {
        std::cin >> a >> b >> c;
        std::cout << maximumScore(a, b, c) << std::endl;
    }
}