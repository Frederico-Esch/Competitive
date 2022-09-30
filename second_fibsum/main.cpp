#include<bits/stdc++.h>
#define sz 3
typedef std::string string;
const int mod = 1e9 + 7;

struct Matrix {
    int mat[sz][sz];
    Matrix(bool id = false){
        for(int i = 0; i < 3*3; i++){
            mat[i/3][i%3] = (id) && (i/3 == i%3);
        }
    }

    Matrix(std::vector<int> list){
        for(int i = 0; i < 3*3; i++){
            mat[i/3][i%3] = list[i];
        }
    }
    Matrix operator*(Matrix b){
        Matrix result;
        for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
        for(int k = 0; k < sz; k++)
        result[i][j] += mat[i][k]*b[k][j];

        return result;
    }

    int* operator[](size_t i){
        return mat[i];
    }
};

void print(Matrix p){

    for(int i = 0; i < sz*sz; i++){
        if(!(i%3))std::cout << std::endl;
        std::cout << p[i/3][i%3] << " ";
    }
}

auto main() -> int {
    Matrix t({1,1,1,
                  0,1,1,
                  0,1,0});
    Matrix result({1,0,0, 1,0,0, 0,0,0});
    int e = 5;

    while(e != 0){

        if(e&1){
            result = t * result ;
        }

        t = t * t;

        e >>= 1;
    }

    //std::cout << "SUM: " << result[0][0] << "\nFIB: " << result[1][0] << std::endl;
    print(result);

    return 0;
}