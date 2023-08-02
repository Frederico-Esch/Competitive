#include <iostream>
#include <array>
#define MOD 1000000007

struct Mat {
    std::array<std::array<int, 3>, 3> values;
    Mat(bool identity = false) {
        for(int i = 0; i < values.size(); i++)
            values[i].fill(0);

        if (identity) {
            for(int i = 0; i < values.size(); i++)
                values[i][i] = 1;
        }
    }

    Mat operator* (Mat a) {
        Mat res;
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < values.size(); j++) {
                for (int k = 0; k < values.size(); k++) {
                    res.values[i][j] += values[i][k] * a.values[k][j];
                    res.values[i][j] %= MOD;
                }
            }
        }
        return res;
    }


    void print() {
        std::cout << values[0][0] << " " << values[0][1] << " " << values[0][2] << std::endl;
        std::cout << values[1][0] << " " << values[1][1] << " " << values[1][2] << std::endl;
        std::cout << values[2][0] << " " << values[2][1] << " " << values[2][2] << std::endl;
    }

};

int summation(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    Mat res(true);
    Mat transformation;
    transformation.values[0][0] = transformation.values[0][1] = transformation.values[0][2] = 1;
    transformation.values[1][1] = transformation.values[1][2] = 1;
    transformation.values[2][1] = 1;

    n -= 1;
    while (n) {
        if (n&1) res = res * transformation;
        transformation = transformation * transformation;
        n >>= 1;
    }
    return (res.values[0][0] + res.values[0][1]) % MOD;
}

int fibSum(int n, int m){
    return (summation(m) - summation(n-1) + MOD) % MOD;
}

int main() {
    std::cout << fibSum(0, 1) << std::endl;
    std::cout << fibSum(1, 2) << std::endl;
    std::cout << fibSum(2, 3) << std::endl;
    std::cout << fibSum(3, 4) << std::endl;

    std::cout << fibSum(0, 10) << std::endl;
    std::cout << fibSum(0, 0) << std::endl;
    std::cout << fibSum(1, 10) << std::endl;
    std::cout << fibSum(0, 2) << std::endl;
    std::cout << fibSum(3, 10) << std::endl;
    std::cout << fibSum(0, 4) << std::endl;
    std::cout << fibSum(5, 10) << std::endl;
    std::cout << fibSum(0, 8) << std::endl;
    std::cout << fibSum(9, 10) << std::endl;
}
