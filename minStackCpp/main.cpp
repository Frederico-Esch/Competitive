#include <iostream>
#include <stack>

struct MinStack {
    std::stack<int> val, min, max;

    void pop() { val.pop(); min.pop(); max.pop(); }

    void push(int value){
        val.push(value);
        if (min.empty()){
            min.push(value);
            max.push(value);
        }
        else {
            min.push(std::min(value, min.top()));
            max.push(std::max(value, max.top()));
        }
    }

    int getMin() {
        return min.top();
    }

    int getMax() {
        return max.top();
    }

    int getTop() {
        return val.top();
    }

};

int main() {
    MinStack minStack;
    minStack.push(-2);
    std::cout << minStack.getMax() << " " << minStack.getTop() << " " << minStack.getMin() << std::endl;
    minStack.push(0);
    std::cout << minStack.getMax() << " " << minStack.getTop() << " " << minStack.getMin() << std::endl;
    minStack.push(3);
    std::cout << minStack.getMax() << " " << minStack.getTop() << " " << minStack.getMin() << std::endl;
    minStack.push(-1);
    std::cout << minStack.getMax() << " " << minStack.getTop() << " " << minStack.getMin() << std::endl;
    minStack.push(-4);
    std::cout << minStack.getMax() << " " << minStack.getTop() << " " << minStack.getMin() << std::endl;
    return 0;
}
