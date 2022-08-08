#include "sum.h"
#include <iterator>

int char_to_int(char a){
    return a-'0';
}

char int_to_char(int a){
    return a + '0';
}

namespace bigints {
    string sum(string a, string b){
        if (a.size() < b.size()) {
            std::swap(a, b);
        }

        std::stringstream sol;
        int carry = 0;
        auto iter_a = a.rbegin(), iter_b = b.rbegin();
        for (; iter_b != b.rend(); iter_a++, iter_b++) {
            auto _a = char_to_int(*iter_a);
            auto _b = char_to_int(*iter_b);
            auto result = _a + _b + carry;
            sol << int_to_char(result%10);
            carry = result/10;
        }

        for (;iter_a != a.rend();iter_a++) {
            auto _a = char_to_int(*iter_a);
            _a += carry;
            sol << int_to_char(_a%10);
            carry = _a / 10;
        }
        if(carry) sol << '1';

        auto result = sol.str();
        std::reverse(result.begin(), result.end());
        return result;
    }
}
