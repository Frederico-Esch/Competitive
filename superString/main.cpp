#include "main.h"

string solve(int pos, int bitmask, std::vector<std::vector<string>> &dp, std::vector<std::vector<string>> &graph){
    if (bitmask == 0) return "";

    if (dp[bitmask][pos] != "") return dp[bitmask][pos];

    string retorno = "";
    for (int i = 0, selection = 1; i < graph.size(); i++, selection <<= 1) {
        if (selection&bitmask){
            string sub_problem = graph[i][pos] + solve(pos, bitmask^selection, dp, graph);
            if (retorno.size()) retorno = retorno.size() > sub_problem.size() ? sub_problem : retorno;
            else retorno = sub_problem;
        }
    }
    dp[bitmask][pos] = retorno;
    return retorno;
}

auto superString(std::vector<string> words) -> string {

    int n = words.size(); std::vector<std::vector<string>> v(n, std::vector<string>(n, ""));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) continue;

            string str = words[j];
            bool found = false;

            for(int left = 0; left < words[i].size(); left++){
                for(int right = 1; right < words[j].size(); right++){
                    string stem = words[i].substr(    left),
                           tail = words[j].substr(0, right);
                    if(stem == tail){
                        str = words[j].substr(right);
                        found = true;
                        break;
                    }
                }
                v[i][j] = str;
                if(found) break;
            }
        }
    }

    //for(auto &sub : v){
    //    for(auto &str : sub){
    //        std::cout << (str==""?"SELF":str) << " ";
    //    }
    //    std::cout << std::endl;
    //}

    string result;
    int bitmask = (1 << n) - 1;
    std::vector<std::vector<string>> dp(bitmask, std::vector<string>(n, ""));

    for (int i = 0 ; i < n; i++) {
        string str = words[i];
        str += solve(i, bitmask^(1<<i), dp, v);
        if (result.size()) {
            result = result.size()>str.size()?str:result;
        }else {
            result = str;
        }
    }

    return result;
}

auto main() -> int {
    std::vector<string> words = {"catg","ctaagt","gcta","ttca","atgcatc"};
    for(auto &str : words){
        std::cout << str << " -> ";
    }
    std::cout << std::endl << std::endl;
    std::cout << superString(words) << std::endl;
    return 0;
}
