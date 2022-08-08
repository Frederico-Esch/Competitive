#include "main.h"
#include "sorting/sort.h"
#include "longest/longest.h"
#include "hamming/hamming.h"
#include "3NP1/3NP1.h"
#include "substring/substring.h"
#include "score/score.h"
#include "andtuples/andtuples.h"


auto main() -> int {
    std::cout << "SORTING: " << std::endl << std::endl;
    sorting::teste();

    std::cout << std::endl<< std::endl << "LONGEST RUN OF ONES: " << std::endl << std::endl;
    longest::teste();

    std::cout << std::endl<< std::endl << "HAMMING: " << std::endl << std::endl;
    hamming::teste();

    std::cout << std::endl << std::endl << "3N+1: " << std::endl << std::endl;
    TNPO::teste();

    std::cout << std::endl << std::endl << "SUBSTRING: " << std::endl << std::endl;
    sub::teste();

    std::cout << std::endl << std::endl << "MAXSCORE: " << std::endl << std::endl;
    score::teste();

    std::cout << std::endl << std::endl << "ANDTUPLES: " << std::endl << std::endl;
    andtuples::teste();

    std::cout << std::endl<< std::endl << "HAMMING SUM: " << std::endl << std::endl;
    hamming::teste_2();

    return 0;
}
