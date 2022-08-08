#include "score.h"

int max_score(std::vector<std::vector<int>> matrix) {
    int n = matrix[0].size();
    int resposta = matrix.size() * (1 << (n - 1)); // considere o primeiro bit como sempre ativado

    for(int i = 1; i < n; i++) { // como o primeiro bit ta sempre ativado, a gente nem ve ele
        int val = 1 << (n - 1 - i);
        int inverted = 0;

        for(auto &row : matrix) {
            if(row[i] != row[0])
                inverted++; // if bit is inverted we inc
        }

        resposta += std::max(inverted, (int)matrix.size() - inverted) * val; // evaluate if we should swap the bits or not, and calc it
    }

    return resposta;
}

void best_matrix(std::vector<std::vector<int>> &matrix) {
    int n = matrix[0].size();
    std::vector<int> invert;

    for(auto &row : matrix){
        invert.push_back(!row[0]);
        row[0] = 1;
    }

    for(int i = 1; i < n; i++) { // como o primeiro bit ta sempre ativado, a gente nem ve ele
        int col_value = 0;

        int row_index = 0;
        for(auto &row : matrix) {
            if(invert[row_index])
                row[i] = !row[i];
            col_value += row[i];
            row_index++;
        }

        if(col_value < matrix.size() - col_value) {
            for(auto &row : matrix) {
                row[i] = !row[i];
            }
        }
    }
}

void print_matrix(std::vector<std::vector<int>> matrix){
    for(auto &sub : matrix){
        for(auto &item : sub){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

namespace score {
    void teste() {
        std::vector<std::vector<int>> valores = {{0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        print_matrix(valores);
        std::cout << max_score(valores) << std::endl;
        best_matrix(valores);
        print_matrix(valores);

        std::cout << std::endl;
        valores = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
        print_matrix(valores);
        std::cout << max_score(valores) << std::endl;
        best_matrix(valores);
        print_matrix(valores);
    }
} // namespace score
