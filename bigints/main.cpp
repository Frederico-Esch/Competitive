#include "main.h"
#include "sum/sum.h"


auto main() -> int {
    string a = "123";
    string b = "9877";
    std::cout << bigints::sum(a, b) << std::endl;
}
