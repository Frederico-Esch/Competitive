#include "seventh.h"

string getHint(string secret, string guess){
    std::multiset<char> letras;
    int bulls = 0, cows = 0;
    std::stringstream result("");

    for (const auto &letra: secret) {
        letras.insert(letra);
    }

    for (int i = 0; i < guess.size(); i++) {
        auto letra = guess[i];

        if(letras.contains(letra)){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                cows++;
            }
            letras.erase(letras.find(letra));
        }
    }
    result << bulls << 'A' << cows << 'B';
    return result.str();
}

void seventh_work(){
    string secret, guess;
    std::cin >> secret >> guess;
    std::cout << getHint(secret, guess) << std::endl;
}
